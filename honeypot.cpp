/**
This class represents a basic honeypot listening and logging connections on port 4444.
@author Dylan Melchior

*/

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

int main(){

    ofstream logFile;
    logFile.open("connectionLog.txt", std::ios::app);

    if (!(logFile.is_open())){
        cout << "Could not open log file." << endl;
        return -1;
    }

    int honeypotSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (honeypotSocket == -1){
        cout << "Could not create socket" << endl;
        return -1;
    }

    sockaddr_in honeypotAddress;
    honeypotAddress.sin_family = AF_INET;
    honeypotAddress.sin_port = htons(4444);
    honeypotAddress.sin_addr.s_addr = INADDR_ANY;

    const int enableSocketReuse = 1;
    if (setsockopt(honeypotSocket, SOL_SOCKET, SO_REUSEADDR, &enableSocketReuse, sizeof(int)) < 0){
        cout << "Socket could not be reused" << endl;
    }
    
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
        sockaddr_in clientAddress;
        socklen_t clientAddressLen = sizeof(clientAddress);
        int clientSocket = accept(honeypotSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);

        if (clientSocket > 0){
            char clientIP[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &clientAddress.sin_addr, clientIP, INET_ADDRSTRLEN);
            logFile <<  clientIP << "|";
            logFile << ntohs(clientAddress.sin_port) << "|";
            logFile << "4444" << endl;
            close(clientSocket);
        }
        else {
            cout << "Could not accept client connection." << endl;
        }
    }
    logFile.close();
}