#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 5'000;
const int AI_MIN = 1, AI_MAX = 10'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
    vector<int> a = inf.readInts(n, AI_MIN, AI_MAX, "a");
    inf.readEoln();
    inf.readEof();
}
