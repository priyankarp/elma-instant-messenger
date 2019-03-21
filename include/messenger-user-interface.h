#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "stopwatch.h"

namespace stopwatch {

    using namespace std::chrono;
    using namespace elma;
    using namespace stopwatch;

    //! A user interface for the a StopWatch object
    class UserInterface : public Process {

        public:

        //! Create a new stopwatch user interface using curses
        //! \param sw A reference to a StopWatch object
        UserInterface(MessengerClient& sw);

        void init() {}
        void start() {}

        //! Display the messeges from all clients on the screen
        void show_messages(int x, int y, string msg);

        //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
        void update();
        void stop() {}

        private:
        MessengerClient& _messengerClient;

    };

}