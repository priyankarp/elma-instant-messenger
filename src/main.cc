#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "stopwatch.h"

using namespace std::chrono;
using namespace elma;
using namespace stopwatch;

int main() {

    Manager m;
    StopWatch stopwatch;
    MessengerClient msgClient;
    UserInterface ui(stopwatch);

    //create one client in one main

    //show on ui that particular client is online

    //ui should be same on all clients



    m.schedule(ui, 10_ms)
     .schedule(stopwatch, 10_ms)     
     .init()
     .run();

    endwin();     
     
}