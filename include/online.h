#ifndef _ELMA_MSGR_ON_H
#define _ELMA_MSGR_ON_H

#include "messenger.h"

namespace messenger {

    using namespace std::chrono;
    using namespace elma;

    class Messenger; // Declare containing class so it can be refered to here
                     // before it is defined in stopwatch.h

    //! A State class to represen the state in which the stopwatch is off
    class OnlineState : public State {

        public:
        //! Construct a new off state
        OnlineState() : State("User online") {}
        void entry(const Event& e) {}
        void during() {} 
        
        //! Perform actions required when switching from off to on
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        
        //! \return A reference to the containing finite state machine object
        Messenger& messenger();

    };

}

#endif