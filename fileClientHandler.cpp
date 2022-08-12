#include "fileClientHandler.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

FileClientHandler::FileClientHandler(const Client &client, ofstream &log_file) :
            client(client), log_file(log_file) {
    if (!log_file.is_open()) {
        throw "Error: file is not open";
    }
}

void FileClientHandler::sendLines(fstream &send_file) const {
    if (!send_file.is_open()) {
        throw "Error: file is not open";
    }
    string line;
    getline(send_file, line);
    while(!line.empty()) {
        client.sendLine(line);
        string response = client.receiveLine();
        log_file << response.c_str() << endl;
    }
}