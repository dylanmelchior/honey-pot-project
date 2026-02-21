/**
This class represents a basic honeypot listening and logging connections on port 4444.
@author Dylan Melchior

REFERENCES 
https://www.geeksforgeeks.org/cpp/socket-programming-in-cpp/
https://www.man7.org/linux/man-pages/man2/listen.2.html
https://www.man7.org/linux/man-pages/man2/accept.2.html
https://www.baeldung.com/cs/socket-api-accept

*/

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

int main(){

    int honeypotSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (honeypotSocket == -1){
        cout << "Could not create socket" << endl;
        return -1;
    }

    sockaddr_in honeypotAddress;
    honeypotAddress.sin_family = AF_INET;
    honeypotAddress.sin_port = htons(4444);
    honeypotAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(honeypotSocket, (struct sockaddr*)&honeypotAddress, sizeof(honeypotAddress)) == -1){
        cout << "Could not bind socket" << endl;
        return -1;
    }

    // Two connections allowed in queue to ensure simplicity - can expand later.
    if (listen(honeypotSocket, 2) == -1){
        cout << "Could not listen on socket" << endl;
        return -1;
    }

    while (true){

        int clientSocket = accept(honeypotSocket, nullptr, nullptr);
        if (!(clientSocket < 0)){
            
        }
        else {

        }

    }


}