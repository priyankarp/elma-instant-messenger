#ifndef _ELMA_MESSENGER_H
#define _ELMA_MESSENGER_H

#include <iostream>
#include <string>

#include "elma/elma.h" // Note installation directory for elma
#include "online.h"
#include "offline.h"
#include "receive.h"
#include "send.h"
#include "messenger-user-interface.h"
#include "messenger-client.h"

namespace messenger {

    using namespace elma;  
    using namespace std;

    //! A stop watch class, that inherits from StateMachine
    class Messenger : public StateMachine {

        public:
        //! Make a new messenger
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

        
        //! Go offline
        vector<string> getAllMsgs();

        private:

        // When overriding the StateMachine class, put state declarations here.
        string client_name;
        string receiveURL, userStatus_online, sendURL, userStatus_offline, _receiverName;
        OnlineState online;
        OfflineState offline;
        SendState send;
        ReceiveState receive;
        MessengerClient msgr_client; //(client_name);

        //Messages
        vector<string> _all_messages;
    };

}


#endif