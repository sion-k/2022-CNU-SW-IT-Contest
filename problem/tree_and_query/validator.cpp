#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
    
    vector<int> a = inf.readInts(n, 0, 1, "a");
    inf.readEoln();
    
    for (int i = 0; i < n - 1; i++) {
        int u = inf.readInt(N_MIN, N_MAX, "u");
        inf.readSpace();

        int v = inf.readInt(N_MIN, N_MAX, "v");
        inf.readEoln();

        ensuref(u != v, "The edge (%d %d) must connect different nodes.", u, v);
    }

    int q = inf.readInt(N_MIN, n, "q");
    inf.readEoln();

    for (int i = 0; i < q; i++) {
        int u = inf.readInt(N_MIN, N_MAX, "u");
        inf.readEoln();
    }

    inf.readEof();
}
