#ifndef ASS_TWO_CLIENT_CLIENT_H
#define ASS_TWO_CLIENT_CLIENT_H

#include <string>
using namespace std;

class Client {
    private:
        const string server_ip;
        const int port_num;
        const int sock;

    public:
        static const int BUFFER_SIZE = 4096;

        /**
         * @brief constructor.
         * @param server_ip - the ip of the server.
         * @param port - the port of the server.
         */
        Client(const string server_ip = "127.0.0.1", const int port = 5555);

        /**
         * @brief sends a line to the server.
         * @param line - the line to send.
         */
        void sendLine(const string line) const;

        /**
         * @brief receives a line from the server.
         * @return the line received.
         */
        string receiveLine() const;

        /**
         * @brief closes the connection.
         */
        void closeConnection() const;
};


#endif //ASS_TWO_CLIENT_CLIENT_H
