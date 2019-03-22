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

/*high_resolution_clock::duration StopWatch::value() {
    if ( current().name() == "on" ) {
        return high_resolution_clock::now() - _start_time + _elapsed;
    } else {
        return _elapsed;
    }
}*/

void Messenger::goOnline() {
    json data = "x : 12";
    msgr_client.post(userStatus_online, data, [this](json& response) {
        cout<<response.dump()<<endl;
    }); 
    msgr_client.process_responses();
    //msgr_client.post()
}

void Messenger::enterReceiver() {

}

void Messenger::sendMessage() {
}

void Messenger::receiveMessage() {

}

void Messenger::goOffline() {

}