#include <iostream>
#include <chrono>
#include <vector>

#include "messenger.h"

using namespace std::chrono;
using namespace elma;
using namespace messenger;

Messenger& ReceiveState::messenger() { return (Messenger&) state_machine(); }

void ReceiveState::exit(const Event& e) {
    //if ( e.name() == "start/stop" ) {
        // User stopped the stopwatch
      //  stopwatch().stop();
    //} else if ( e.name() == "lap" ) {
        // User adds a lap to the stopwatch lap list
    //    stopwatch().lap();
    //}
}
