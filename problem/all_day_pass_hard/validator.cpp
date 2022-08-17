#include "testlib.h"
 
const int N_MIN = 1, N_MAX = 100'000;
const int AI_MIN = 1, AI_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
    inf.readInts(n, AI_MIN, AI_MAX, "ai");
    inf.readEoln();
    inf.readEof();
}
