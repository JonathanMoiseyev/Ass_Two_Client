#ifndef ASS_TWO_CLIENT_FILE_CLIENT_HANDLER_H
#define ASS_TWO_CLIENT_FILE_CLIENT_HANDLER_H

#include "client.h"
#include <fstream>

class FileClientHandler {
    private:
        const Client &client;
        ofstream &log_file;

    public:
        FileClientHandler(const Client &client, ofstream &log_file);
        void sendLines(fstream &send_file) const;
};

#endif //ASS_TWO_CLIENT_FILE_CLIENT_HANDLER_H
