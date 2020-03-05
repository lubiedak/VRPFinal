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

    app.port(18080).multithreaded().run();
}