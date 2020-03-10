#include "ApiController.h"
#include "crow_all.h"
#include "../random/RandomModeExecutor.h"


void ApiController::run(void){
    crow::SimpleApp app;
	
	CROW_ROUTE(app,"/random/<int>")
	([](int n){
        RandomModeExecutor executor;
        auto s = executor.generateAndSolveRandomProblems(n);
        std::ostringstream os;
        for (auto const& x : s)
        {
            os << x.first  // string (key)
                    << ':'
                    << std::endl 
                    << x.second // string's value 
                    << std::endl ;
        }
        return crow::response(os.str());
    });

    CROW_ROUTE(app,"/random/problem")
	([](){
        RandomModeExecutor executor;
        auto problem = executor.createProblem("rest", "ProblemGenParamsCfg");
        crow::json::wvalue response = problem.toJson();
        
        return response;
    });

    CROW_ROUTE(app,"/random/problem/solution")
	([](){
        RandomModeExecutor executor;
        auto problem = executor.createProblem("rest", "ProblemGenParamsCfg");
        crow::json::wvalue response = executor.solveProblem("rest", problem).toJson();
        
        return response;
    });

    CROW_ROUTE(app,"/random/problem/solution/drawing")
	([](){
        RandomModeExecutor executor;
        crow::json::wvalue response;
        auto problem = executor.createProblem("rest", "ProblemGenParamsCfg");
        response[""][0] = problem.toJsonForDrawing();
        response[""][1] = executor.solveProblem("rest", problem).toJsonForDrawing();
        
        return response;
    });

    app.port(18080).multithreaded().run();
}