#include "ApiController.h"
#include "crow_all.h"
#include "../random/RandomModeExecutor.h"
#include <iostream>

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

    CROW_ROUTE(app, "/problem/solve")
    .methods("POST"_method)
    ([](const crow::request& req){
        auto json = crow::json::load(req.body);
        if (!json)
            return crow::response(400);
        crow::logger logger("api", crow::LogLevel::INFO);
        logger<<"dobry json";
        logger<<json;
        Problem p = Problem(json);
        logger<<"Po problemie";

        return crow::response(p.toJson());
    });

    app.port(18080).multithreaded().run();
}