#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <cstring>
#include <netdb.h>
#include "config.h"

using namespace std;

int main() {

    /*
    int connected = 0; // Used to loop the program

    string server = "irc.freenode.net"; // network address
    int port = 6667; // server port
    string nick = "NICK Somebot"; // NICK raw
    string user = "USER Somebot randomtext israndom :My first c++ bot"; // USER raw
    */

    /** Structs that hold the socket information **/

    struct sockaddr_in addr;
    struct hostent *host;

    /** Get an ip address from the network to connect to **/
    host = gethostbyname(server.c_str());

    /** Fill the members of the socket structs required to connect **/

    addr.sin_addr.s_addr = *(unsigned long*)host->h_addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons((unsigned short)port);
    int sockd = socket(AF_INET, SOCK_STREAM, 0);

    /** Connect to address **/
    connect(sockd, (struct sockaddr *)&addr, sizeof(addr));

    cout << "Connecting to: " << server << endl;
    send(sockd, nick.c_str(), nick.size(), 0); // Converts nick string to c-array and sends it to server
    cout << "Sent: " << nick << " to server" << endl;
    send(sockd, user.c_str(), user.size(), 0); // Converts user string to c-array and sends it to server
    cout << "sent: " << user << " to server" << endl;

    char sockbuff[4096]; // array to hold the incoming socket data
    while (connected < 1) {
        memset(&sockbuff, '\0', sizeof(sockbuff)); // make sure sockbuff[] is empty
        recv(sockd, sockbuff, 4096, 0); // Recieve all the data from server to sockbuff[]
        cout << sockbuff << endl;;
    }


    return 0;
}