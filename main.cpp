#include <crow.h>
using namespace std;
int main()
{
    crow::SimpleApp app;
    CROW_ROUTE(app, "/string")
    ([]{ 
        return "Hello world"; 
    });

    CROW_ROUTE(app, "/array")
    ([]{
        crow::json::wvalue x;
        std::vector<int> ids = {1, 2, 3};
        std::vector<string> names = {"JavaScript", "C++", "PHP"};
        size_t i;
        for (i = 0; i < ids.size(); ++i)
        {
            x[i]["id"] = ids.at(i);
            x[i]["name"] = names.at(i);
        }
        return x; 
    });
    
    CROW_ROUTE(app, "/object")
    ([]{
            // crow::json::wvalue x;
            // x = {
            //     {"a", 1},
            //     {"b", 2}
            // };  
            crow::json::wvalue x({{"message", "Hello, World!"}});
            x["message2"] = "Hello, World.. Again!";
            return x; 
        });

    CROW_ROUTE(app, "/hello/<int>")
    ([](int count){
        if (count > 100)
            return crow::response(400);
        std::ostringstream os;
        os << count << " bottles of beer!";
        return crow::response(os.str()); 
    });

    CROW_ROUTE(app, "/add").methods("POST"_method)([](const crow::request &req){
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(crow::status::BAD_REQUEST); // same as crow::response(400)
        int sum = x["a"].i()+x["b"].i();
        std::ostringstream os;
        os << sum;
        return crow::response{os.str()}; 
    });

    app.port(18080).multithreaded().run();
    return 0;
}
