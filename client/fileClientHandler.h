#ifndef ASS_TWO_CLIENT_FILE_CLIENT_HANDLER_H
#define ASS_TWO_CLIENT_FILE_CLIENT_HANDLER_H

#include "client.h"
#include <fstream>

/**
 * @brief The File_client_handler class
 *
 * This class is responsible for handling the client.
 * It creates a client, and handles it.
 */
class FileClientHandler {
    private:
        const Client &client;
        ofstream &log_file;

    public:
        /**
         * Constructor
         * @param client - client object
         * @param log_file - the file to write the log to
         */
        FileClientHandler(const Client &client, ofstream &log_file);

        /**
         * Sends lines from the file to the server
         * @param send_file - the file to send
         */
        void sendLines(fstream &send_file) const;
};

#endif //ASS_TWO_CLIENT_FILE_CLIENT_HANDLER_H
