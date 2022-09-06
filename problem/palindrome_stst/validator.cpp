#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
    string s = inf.readToken("[st]+", "s");
    inf.readEoln();
    ensuref(s.size() == n, "size of s is not %d", n);
    inf.readEof();
}
