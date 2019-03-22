#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "messenger.h"

namespace messenger {

    using namespace std::chrono;
    using namespace elma;
    //using namespace messenger;

    //! A user interface for the a Messenger object
    class UserInterface : public Process {

        //class Messenger;

        public:

        //! Create a new stopwatch user interface using curses
        //! \param sw A reference to a Messenger object
        UserInterface(Messenger& messenger);

        void init() {}
        void start() {}

        //! Display the messeges from all clients on the screen
        void show_messages(int x, int y, string msg);

        //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
        void update();
        void stop() {}

        private:
        Messenger& _messenger;
        int row,col;

    };
}
