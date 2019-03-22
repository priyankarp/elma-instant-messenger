#include <unistd.h>
#include "messenger.h"

using namespace messenger;
using namespace elma;

UserInterface::UserInterface(Messenger& msgr) : Process("messenger"), _messenger(msgr) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor

    				/* to store the number of rows and *
					 * the number of colums of the screen */
    getmaxyx(stdscr,row,col);		/* get the number of rows and columns */

};

void UserInterface::show_messages(int x, int y, string msg) {

    // Print the time at the desired position.
    // mvprintw just calls sprintf  
    int n = msg.length(); 
  
    // declaring character array 
    char msg_char_array[n + 1]; 
  
    // copying the contents of the 
    // string to char array 
    strcpy(msg_char_array, msg.c_str()); 
    mvprintw(x, y, msg_char_array);
}

void UserInterface::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR (which is
    // ignored below since there is no condition in the switch statement)
    int c = getch();

    switch ( c ) {            
        case 'o':
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
            emit(Event("offline"));
            halt();
            break;
    }

    // OUTPUT
    mvprintw(1, 1, "Welcome to Elma-Instant-Messenger");

    mvprintw(3, 1, "Follow the legend below to start using the messenger");
    //show_messages(1,1,_messenger.value()); // change .value() to .msgstring() - add this method
    mvprintw(4,1,"online(o), send msg(s), receive msgs(r), offline(q)");
    vector<string> temp = _messenger.getAllMsgs();
    for ( int i=0; i < temp.size(); i++ ) {
        show_messages(6+i, 20, temp[i]);
    }

    // NOTE: Since the stopwatch is running every 10 ms, we should sleep
    //       the ui to give processing time back to the OS. It is debatable
    //       whether this is the right place to put this. It could also become
    //       an Elma feature, or it could go in the StopWatch class, etc.
    //       The number 9999 should also be a parameter and not a constant.
    usleep(9999);

}