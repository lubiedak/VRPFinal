#include "ApiController.h"
#include "crow_all.h"
#include "../random/RandomModeExecutor.h"


void ApiController::run(void){
    crow::SimpleApp app;
	
	CROW_ROUTE(app,"/random/<int>")
	([](int n){
        RandomModeExecutor executor;
        executor.generateAndSolveRandomProblems(n);
        if (n > 100)
            return crow::response(400);
        std::ostringstream os;
        os << n << " bottles of beer!";
        return crow::response(os.str());
    });

    app.port(18080).multithreaded().run();
}