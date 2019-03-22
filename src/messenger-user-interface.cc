#include <unistd.h>
#include "messenger.h"


UserInterface::UserInterface(Messenger& msgr) : Process("messenger"), _messenger(msgr) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
};

void UserInterface::show_messeges(int x, int y, string msg) {

    // Print the time at the desired position.
    // mvprintw just calls sprintf
    mvprintw(x,y,"test msg", 
        //std::chrono::duration_cast<std::chrono::minutes>(d).count(),
        //std::chrono::duration_cast<std::chrono::seconds>(d).count()%60,
        //(std::chrono::duration_cast<std::chrono::milliseconds>(d).count()%1000)/10
    );
}

void UserInterface::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR (which is
    // ignored below since there is no condition in the switch statement)
    int c = getch();

    switch ( c ) {            
        case 'n':
            emit(Event("online"));
            break;
        case 's':
            emit(Event("send"));
            clear(); // Clear the screen of old stuff
            break;
        case 'r':
            emit(Event("receive"));
            break;
        case 'q':
            std::cout << "halting\n";
            halt();
            break;
    }

    // OUTPUT
    
    //show_messages(1,1,_messenger.value()); // change .value() to .msgstring() - add this method
    mvprintw(3,1,"online(n), send(s), receive(r), offline/quit(q)");
    /*for ( int i=0; i<_messengerClient.laps().size(); i++ ) {
        mvprintw(5+i, 1, "Lap %d", _messengerClient.laps().size()-i);
        show_messages(5+i, 10, _messengerClient.laps()[i]);
    }*/

    // NOTE: Since the stopwatch is running every 10 ms, we should sleep
    //       the ui to give processing time back to the OS. It is debatable
    //       whether this is the right place to put this. It could also become
    //       an Elma feature, or it could go in the StopWatch class, etc.
    //       The number 9999 should also be a parameter and not a constant.
    usleep(9999);

}