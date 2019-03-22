#ifndef _ELMA_MESSENGER_H
#define _ELMA_MESSENGER_H

#include "elma/elma.h" // Note installation directory for elma

#include "messenger-user-interface.h"
#include "messenger-client.h"

namespace messenger{
    using namespace elma;  
    using namespace messenger;  

    class OnlineState : public State {
        public:
        OnlineState() : State("User online") {}
        void entry(const Event& e) {}
        void during() {} 
        void exit(const Event& e) {
            //emit(Event("off"));
        }
    };


    class OfflineState : public State {
        public:
        OfflineState() : State("User offline") {}
        void entry(const Event& e) {}
        void during() {} 
        void exit(const Event& e) {
            //emit(Event("off"));
        }
    };

    class SendState : public State {
        public:
        SendState() : State("Sending msg") {}
        void entry(const Event& e) {}
        void during() {} 
        void exit(const Event& e) {
            //emit(Event("off"));
        }
    };

    class ReceiveState : public State {
        public:
        ReceiveState() : State("Receiving msgs") {}
        void entry(const Event& e) {}
        void during() {} 
        void exit(const Event& e) {
            //emit(Event("off"));
        }
    };

    //! A stop watch class, that inherits from StateMachine
    class Messenger : public StateMachine {

        public:
        //! Make a new stopwatch
        Messenger(string name){
            client_name = name;
        }

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
        //OnState on;
        //OffState off;
        string client_name;

        //states
        OnlineState online;
        OfflineState offline;
        SendState send;
        ReceiveState receive;

        MessengerClient myClient; //(client_name);

        /*// Other private variables
        bool _running;
        high_resolution_clock::time_point _start_time;
        high_resolution_clock::duration _elapsed;
        vector<high_resolution_clock::duration> _laps;*/

    };

}


#endif