#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "messenger.h"

using namespace std::chrono;
using namespace elma;
using namespace messenger;
using namespace std;

int main() {

    Manager m;
    string name;
    cout << "\nEnter username: ";
    cin >> name;
    Messenger msgr(name);
    UserInterface ui(msgr);

    m.schedule(ui, 10_ms)
     .schedule(msgr, 10_ms)     
     .init()
     .run();

    endwin();     


     
}