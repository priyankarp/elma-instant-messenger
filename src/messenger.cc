#include <chrono>
#include <vector>
#include <iostream>

#include "messenger.h"

using namespace std::chrono;
using namespace elma;
using namespace messenger;
using namespace std;

Messenger::Messenger(string name) : StateMachine(name) {

    //Set client name 
    this->client_name = name;

    sendURL = "http://messenger-server/post-messages";

    receiveURL.append("http://messenger-server/get-messages/");
    receiveURL.append(client_name); //+ client_name;

    userStatus_online.append("http://messenger-server/status/");
    userStatus_online.append(client_name);
    userStatus_online.append("/true");

    userStatus_offline.append("http://messenger-server/status/");
    userStatus_offline.append(client_name);
    userStatus_offline.append("/false");

    // Define state machine initial states and transitions here
    set_initial(offline);
    set_propagate(false);
    add_transition("online", offline, online);
    add_transition("send", online, send);
    add_transition("send", receive, send);   
    add_transition("send", send, send); 
    add_transition("receive", online, receive);  
    add_transition("receive", send, receive);   
    add_transition("receive", receive, receive);             
    add_transition("offline", online, offline);
    add_transition("offline", send, offline);
    add_transition("offline", receive, offline);
    // Make sure we start in the right condition
    //reset();
}

void Messenger::goOnline() {
    json data = "x : 12";
    msgr_client.post(userStatus_online, data, [this](json& response) {
        if(response["result"] == "ok"){
            //cout << "\npri is online." << endl;
            string temp = "\n" + client_name + " is online.";
            _all_messages.push_back(temp);
        }
    }); 
    msgr_client.process_responses();
}

void Messenger::enterReceiver() {
    string t;
    cout << "\nEnter name of the receiver : " << endl ;
    cin >> t;
    this->_receiverName = t;
    _all_messages.push_back("\nSending msgs to " + _receiverName);
}

void Messenger::sendMessage() {
    json data;
    string msg;
    cout << "\nEnter msg: ";
    //cin.ignore();
    //getline(cin, msg);
    cin >> msg;
    data["sender"] = this->client_name;
    data["recipient"] = this->_receiverName;
    data["message"] = msg;
     _all_messages.push_back("\n" + this->client_name + ": " + msg);
    msgr_client.post(sendURL, data, [this](json& response) {
        if(response["result"] == "ok"){
        }
    }); 
    msgr_client.process_responses();
}

void Messenger::receiveMessage() {

    msgr_client.get(receiveURL, [&](json& response) {
         if(response["result"] == "ok"){
            std::vector< std::pair<string, string> > temp = response["messages"];
            for (auto x : temp){
                string sender = this->_receiverName;
                string msg = std::get<1>(x);
                _all_messages.push_back("\n" + sender + ": " + msg);
            }
        }
    });
    msgr_client.process_responses();
}

void Messenger::goOffline() {
    json data = "x : 12";
    msgr_client.post(userStatus_offline, data, [this](json& response) {
        if(response["result"] == "ok"){
            //cout << "\npri is online." << endl;
            string temp = "\n" + client_name + " is offline.";
            _all_messages.push_back(temp);
        }
    }); 
    msgr_client.process_responses();
}

vector<string> Messenger::getAllMsgs() {
    return _all_messages;
}