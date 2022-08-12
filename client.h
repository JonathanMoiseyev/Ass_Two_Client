#ifndef ASS_TWO_CLIENT_CLIENT_H
#define ASS_TWO_CLIENT_CLIENT_H

#include <string>
using namespace std;

class Client {
    const string server_ip;
    const int port_num;
    const int sock;

    public:
        static const int BUFFER_SIZE = 4096;
        Client(const string server_ip, const int port);
        void sendLine(const string line) const;
        string receiveLine() const;
        void closeConnection() const;
};


#endif //ASS_TWO_CLIENT_CLIENT_H
