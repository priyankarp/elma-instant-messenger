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
    std::map<string, std::vector< std::pair<string, string> > recipientToMessages;
    std::map<string, bool> userStatus;

    svr.Post("/post-messages", [&](const Request& req, Response& res) {
        std::cout << "Received post message request" << "\n";
        json request, result;

        try {
            request = json::parse(req.body);
            string sender = request["sender"];
            string recipient = request["recipient"];
            string message = request["message"];
            vector<string> temp;
            if (recipientToMessages.find(recipient) != recipientToMessages.end()) {
                temp = recipientToMessages[recipient];
            }
           
            temp.push_back(std::make_pair(recipient, message));
            recipientToMessages[recipient] = temp;

        } catch(json::exception e) {
            result["result"] = "error";
            result["message"] = e.what();
            res.set_content(result.dump(), "json");
            return;
        }

        result["result"] = "ok";
        res.set_content(result.dump(), "json");
    });

    svr.Post(R"(/online/(\s+)/(\s+))", [&](const Request& req, Response& res) {
        std::cout << "Got new online request for id = " << req.matches[1] << " status = " << req.matches[2] << "\n";
        string user = req.matches[1];
        bool status;
        if(req.matches[2] == "true") {
            status = true;
        } else {
            status = false;
        }
        userStatus[user] = status;
    });
 
    svr.Get(R"(/get-messages/(\s+))", [&](const Request& req, Response& res) {
        std::cout << "Got get message request for id = " << req.matches[1] << "\n";
        json result;
        try {
            string recipient = req.matches[1];
            if (recipientToMessages.find(recipient) != recipientToMessages.end()){
                result["messages"] = recipientToMessages[recipient];
            } else {
                vector<string> temp;
                request["messages"] = temp;
            }
        } catch(json::exception e) {
            result["result"] = "error";
            result["message"] = e.what();
            res.set_content(result.dump(), "json");
            return;
        }
        res.set_content(result.dump(), "json");
    });

    svr.listen("0.0.0.0", 80); // Note, only this port is exposed to 
                                 // host machine

    std::cout << "You can't see me, because svr.listen never returns\n";

}