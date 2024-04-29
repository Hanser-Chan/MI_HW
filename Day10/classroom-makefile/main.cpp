#include "src/easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[]) {
    LOG(INFO) << "this is info log";
    LOG(ERROR) << "this is error log";
    LOG(DEBUG) << "this is debug log";
    return 0;
}