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

        //! Go online
        void goOnline();

        //! Enter receivers user-name
        void enterReceiver();

        //! send messages
        void sendMessage();

        //! Receive messages
        void receiveMessage();

        //! Go offline
        void goOffline();

        //! Get the time stored by the stopwatch
        //high_resolution_clock::duration value();

        //! Get a list of lap times
        //const vector<high_resolution_clock::duration>& laps() { return _laps; }

        private:

        // When overriding the StateMachine class, put state declarations here.

        string client_name;

        //states
        OnlineState online;
        OfflineState offline;
        SendState send;
        ReceiveState receive;

        MessengerClient msgr_client; //(client_name);

        //Messages
        vector<string> _sent_messages;
        vector<string> _received_messages;

        string _receiverName;
        string sendURL = "http://messenger-server/post-messages";
        string receiveURL = "http://messenger-server/get-messages/" + client_name;
        string userStatus_online = "http://messenger-server/status/" +  client_name + "/true";
        string userStatus_offline = "http://messenger-server/status/" +  client_name + "/false";
    };

}


#endif