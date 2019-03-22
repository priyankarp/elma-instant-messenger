#include <iostream>
#include <chrono>
#include <vector>

#include "messenger.h"

using namespace std::chrono;
using namespace elma;
using namespace messenger;

Messenger& SendState::messenger() { return (Messenger&) state_machine(); }

void SendState::entry(const Event& e) {
    messenger().sendMessage();
    //messenger().receiveMessage();

}

void SendState::exit(const Event& e) {
    messenger().receiveMessage();
}
