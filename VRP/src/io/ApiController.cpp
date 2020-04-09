#include "ApiController.h"
#include "crow_all.h"
#include "../random/RandomModeExecutor.h"
#include "DistanceMatrix.h"
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

    CROW_ROUTE(app, "/problem/solve")
    .methods("POST"_method)
    ([](const crow::request& req){
        auto json = crow::json::load(req.body);

        RandomModeExecutor executor;
        if (!json)
            return crow::response(400);
        Problem p = Problem(json);
        Solution s = executor.solveProblem("rest", p);
        return crow::response(s.toJson());
    });

    CROW_ROUTE(app, "/problem/solve/cities")
    .methods("POST"_method)
    ([](const crow::request& req){
        auto json = crow::json::load(req.body);

        RandomModeExecutor executor;
        if (!json)
            return crow::response(400);
        Problem p = Problem(json);
        Solution s = executor.solveProblemForCities("rest", p);
        return crow::response(s.toJson());
    });

    app.port(18080).multithreaded().run();
}