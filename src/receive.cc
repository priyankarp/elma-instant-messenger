#include <iostream>
#include <chrono>
#include <vector>

#include "messenger.h"

using namespace std::chrono;
using namespace elma;
using namespace messenger;

Messenger& ReceiveState::messenger() { return (Messenger&) state_machine(); }

void ReceiveState::entry(const Event& e) {
    messenger().receiveMessage();
}

void ReceiveState::exit(const Event& e) {
    messenger().receiveMessage();
}
