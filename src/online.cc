#include <iostream>
#include <chrono>
#include <vector>

#include "messenger.h"

using namespace std::chrono;
using namespace elma;
using namespace messenger;

Messenger&OnlineState:: messenger() { return (Messenger&) state_machine(); }

void OnlineState::entry(const Event& e) {
    messenger().goOnline();
    messenger().enterReceiver();
    messenger().receiveMessage();
}

void OnlineState::exit(const Event& e) {
    messenger().receiveMessage();
}
