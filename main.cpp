#include "client/fileClientHandler.h"

/**
 * The main function for the client.
 * @param argc - number of arguments
 * @param argv - array of arguments, that should have the address of the classified file,
 * and the address of the unclassified file
 * @return 0 (the default return value of the main function)
 */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        throw "Error: not enough arguments";
    }

    string unclassified_address = argv[1];
    string classified_address = argv[2];

    fstream &send_file = *(new fstream(classified_address, ios::in));
    ofstream &log_file = *(new ofstream(unclassified_address, ios::out));

    if (!send_file.is_open()) {
        throw "Error opening file : " + classified_address;
    }

    if (!log_file.is_open()) {
        throw "Error opening file : " + unclassified_address;
    }

    Client &client = *(new Client());
    FileClientHandler &file_client_handler = *(new FileClientHandler(client, log_file));
    file_client_handler.sendLines(send_file);

    send_file.close();
    log_file.close();
    client.closeConnection();
    delete &client;
    delete &send_file;
    delete &log_file;
    delete &file_client_handler;
}