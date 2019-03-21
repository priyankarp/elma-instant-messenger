#include "httplib/httplib.h"
#include "json/json.h"
#include <iostream>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <vector>

using namespace std;

long int unix_timestamp() {
    time_t t = std::time(0);
    long int now = static_cast<long int> (t);
    return now;
}

int main(void)
{
    using namespace httplib;
    using nlohmann::json; 

    Server svr;

    // Example messegesd for saving temperatures recorded at specific x, y locations
    // This should be at least replaced with a databases class
    // Or better yet, use an actual databse like sqlite, mysql, postgress, etc.
    //  id              timestamp  x       y       temperature
    std::map<int, std::tuple<double, string, string> > messeges;
    int next_id = 0;

    svr.Post("/send", [&](const Request& req, Response& res) { 

        json request, result;

        try {
            request = json::parse(req.body);
        } catch(json::exception e) {
            result["result"] = "error";
            result["message"] = e.what();
            res.set_content(result.dump(), "json");
            return;
        }

        std::cout << "Got new send request " << request.dump() << std::endl;  

        messeges[next_id] = std::make_pair(
          unix_timestamp(),
          request["user"] = std::to_string(request["user"]),
          request["message"] = std::to_string(request["message"])
        );

        result["result"] = "ok";
        result["id"] = next_id++;
        res.set_content(result.dump(), "json");

    });

    svr.Get(R"/receive", [&](const Request& req, Response& res) {
        std::cout << "Received a message from = " << req.matches[1] << "\n";
        auto id = std::stoi(req.matches[1].str());
        json result;
        if ( messeges.find(id) != messeges.end() ) {
            result = { 
                { "result", "ok" },
                { "id", id },
                { "timestamp", std::get<0>(messeges[id]) },
                { "x", std::get<1>(messeges[id]) },
                { "y", std::get<2>(messeges[id]) },
                { "temperature", std::get<3>(messeges[id]) }                                      
            };
        } else {
            result["result"] = "error";
            result["message"] = "not found";
            res.status = 404;
        }
        res.set_content(result.dump(), "json");
    });

    svr.listen("0.0.0.0", 80); // Note, only this port is exposed to 
                                 // host machine

    std::cout << "You can't see me, because svr.listen never returns\n";

}

