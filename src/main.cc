#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "messenger.h"
//#include "messenger-user-interface.h"

using namespace std::chrono;
using namespace elma;
using namespace messenger;

int main() {

    Manager m;
    Messenger msgr("pri");
    //MessengerClient msgClient;
    UserInterface ui(msgr);

    //create one client in one main

    //show on ui that particular client is online

    //ui should be same on all clients



    m.schedule(ui, 10_ms)
     .schedule(msgr, 10_ms)     
     .init()
     .run();

    endwin();     


     
}