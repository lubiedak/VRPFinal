#include "crow_all.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });
	
	CROW_ROUTE(app, "/json")
	([]{
	    crow::json::wvalue x;
	    x["message"] = "Hello, World!";
		x["anotherMessage"] = "Hllo, World!";
	    return x;
	});
	
	CROW_ROUTE(app,"/hello/<int>")
	([](int count){
	    if (count > 100)
	        return crow::response(400);
	    std::ostringstream os;
	    os << count << " bottles of beer!";
	    return crow::response(os.str());
	});

    app.port(18080).multithreaded().run();
}