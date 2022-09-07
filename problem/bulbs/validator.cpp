#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 200'000;
const int AI_MIN = 1, AI_MAX = 5'000;
const int BI_MIN = 0, BI_MAX = 1;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();

    vector<int> a = inf.readInts(n, AI_MIN, AI_MAX, "a");
    inf.readEoln();

    vector<int> b = inf.readInts(n, BI_MIN, BI_MAX, "b");
    inf.readEoln();

    inf.readEof();
}
