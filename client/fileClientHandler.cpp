#include "fileClientHandler.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

FileClientHandler::FileClientHandler(const Client &client, ofstream &log_file) :
            client(client), log_file(log_file) {
    if (!log_file.is_open()) {
        cout <<  "Error: log file is not open" << endl;
        exit(1);
    }
}

void FileClientHandler::sendLines(fstream &send_file) const {
    if (!send_file.is_open()) {
        cout << "Error: send file is not open" << endl;
        exit(1);
    }
    string line;
    getline(send_file, line);
    while(!line.empty()) {
        client.sendLine(line);
        string response = client.receiveLine();
        try {
            log_file << response << endl;
        } catch (const char *msg) {
            if (strcmp(msg, "connection is closed") == 0) {
                return;
            } else {
                cout << "error";
                exit(1);
            }
        }
        getline(send_file, line);
    }

    client.sendLine("END\r");
}