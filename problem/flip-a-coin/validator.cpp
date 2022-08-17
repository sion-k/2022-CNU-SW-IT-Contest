#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 2, N_MAX = 20;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(N_MIN, N_MAX, "n");
    ensuref(n % 2 == 0, "n must be even");
    inf.readEoln();
    string s = inf.readToken("[01]+");
    inf.readEoln();
    inf.readEof();
}
