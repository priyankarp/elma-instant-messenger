#ifndef _ELMA_MESSENGER_H
#define _ELMA_MESSENGER_H

#include "elma/elma.h" // Note installation directory for elma

#include "online.h"
#include "offline.h"
#include "receive.h"
#include "send.h"
#include "messenger-user-interface.h"
#include "messenger-client.h"

namespace messenger {

    using namespace elma;  
    //using namespace messenger;

    //! A stop watch class, that inherits from StateMachine
    class Messenger : public StateMachine {

        public:
        //! Make a new stopwatch
        Messenger(string name);

        /*//! Start the stopwatch
        void begin();

        //! Reset the stopwatch to zero and erase laps
        void reset();

        //! Stop the stopwatch
        void stop();

        //! Add a lap time to the list of lap times.
        void lap();

        //! Get the time stored by the stopwatch
        high_resolution_clock::duration value();

        //! Get a list of lap times
        const vector<high_resolution_clock::duration>& laps() { return _laps; }*/

        private:

        // When overriding the StateMachine class, put state declarations here.

        string client_name;

        //states
        OnlineState online;
        OfflineState offline;
        SendState sending;
        ReceiveState receive;

        MessengerClient myClient; //(client_name);
    };

}


#endif