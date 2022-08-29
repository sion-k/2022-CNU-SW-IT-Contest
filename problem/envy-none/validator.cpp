#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 200'000;
const long long AI_MIN = 1, AI_MAX = 1'000'000'000'000LL;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
    vector<long long> a = inf.readLongs(n, AI_MIN, AI_MAX, "a");
    inf.readEoln();
    inf.readEof();
}
