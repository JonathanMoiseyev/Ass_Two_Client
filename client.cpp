#include "client.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

Client::Client(const std::string server_ip, const int port): server_ip(server_ip), port_num(port),
                    sock(socket(AF_INET, SOCK_STREAM, 0)){
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(server_ip.c_str());
    sin.sin_port = htons(port_num);

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
}

void Client::sendLine(const std::string line) const {
    char const *data_addr = line.c_str();
    int data_len = line.length();
    int sent_bytes = send(sock, data_addr, data_len, 0);

    if (sent_bytes < 0) {
        // error
    }
}

string Client::receiveLine() const {
    char buffer[BUFFER_SIZE];
    int read_bytes = recv(sock, buffer, BUFFER_SIZE, 0);
    if (read_bytes == 0) {
        // connection is closed
        throw "connection is closed";
    } else if (read_bytes < 0) {
        // error
        throw "error";
    }
    return string(buffer);
}

void Client::closeConnection() const {
    close(sock);
}
