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
    UserInterface ui(msgr);

    m.schedule(ui, 10_ms)
     .schedule(msgr, 10_ms)     
     .init()
     .run();

    endwin();     


     
}