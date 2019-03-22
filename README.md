# elma-instant-messenger
EE590 Final Project - A simple instant messenger using Elma (C++)


Application Specifications
---
The IM communication can happen between two or more people.
Only text based messeges.
Connection will be established using TCP IP communication.
RealTime Communication.
No authentication required.

Installation
---

    git clone https://github.com/priyankarp/elma-instant-messenger.git
    cd elma-instant-messenger
    docker run -v $PWD:/source -it klavins/elma:latest bash
    make
    make docs

Execution
---
To run the stopwatch, type

    bin/messenger-server
    bin/messenger



Resources
---
Elma Library
socket library
httlib
Possibly a GUI library (still researching on this) or a android simulator


Personal Milestones for the project:
---
03/12/2019 - Finalizing API for the messenger 
03/16/2019 - Get multiple connections working 
03/18/2019 - Figuring out testing strategy, writing tests
03/20/2019 - Getting some GUI working
03/22/2019 - Final Project submission
