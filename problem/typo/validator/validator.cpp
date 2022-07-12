#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    inf.readLine("[\\(\\)]{1,100000}", "s");
    inf.readEof();
}
