#include <chrono>
#include <vector>

#include "messenger.h"

using namespace std::chrono;
using namespace elma;
using namespace messenger;

Messenger::Messenger(string name) : StateMachine(name) {

    //Set client name 
    this->client_name = name;

    // Define state machine initial states and transitions here
    set_initial(online);
    set_propagate(false);
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
}

void StopWatch::begin() {
    _start_time = high_resolution_clock::now();
}

void StopWatch::reset() {
    _elapsed = high_resolution_clock::duration::zero();
    _laps.clear();
}

void StopWatch::stop() {
    _elapsed += high_resolution_clock::now() - _start_time;
}

void StopWatch::lap() {
    _laps.insert(_laps.begin(), value());
}*/