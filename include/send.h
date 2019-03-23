#ifndef _ELMA_MSGR_SEND_H
#define _ELMA_MSGR_SEND_H

#include "messenger.h"

namespace messenger {

    using namespace std::chrono;
    using namespace elma;

    class Messenger; // Declare containing class so it can be refered to here
                     // before it is defined in messenger.h

    //! A State class to represen the state in which the messenger is sending state
    class SendState : public State {

        public:
        //! Construct a new Send state
        SendState() : State("Sending msg") {}
        void entry(const Event& e);
        void during() {} 
        
        //! Perform actions required when switching from Send to other
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        
        //! \return A reference to the containing finite state machine object
        Messenger& messenger();

    };

}

#endif