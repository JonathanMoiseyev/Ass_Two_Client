#ifndef ASS_TWO_CLIENT_FILE_CLIENT_HANDLER_H
#define ASS_TWO_CLIENT_FILE_CLIENT_HANDLER_H

#include "client.h"
#include <fstream>

class FileClientHandler {
    private:
        const Client &client;
        ofstream &log_file;

    public:
        /**
         * @brief constructor
         * @param client - client object
         * @param log_file - the file to write the log to
         */
        FileClientHandler(const Client &client, ofstream &log_file);

        /**
         * @brief sends lines from the file to the server
         * @param send_file - the file to send
         */
        void sendLines(fstream &send_file) const;
};

#endif //ASS_TWO_CLIENT_FILE_CLIENT_HANDLER_H
