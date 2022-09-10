#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 2, N_MAX = 100'000;
const int AI_MIN = 1, AI_MAX = 1'000'000;

const int M_MIN = 1, M_MAX = 300'000;
const int W_MIN = 1, W_MAX = 1'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();

    vector<int> a = inf.readInts(n, AI_MIN, AI_MAX, "a");
    inf.readEoln();

    int m = inf.readInt(M_MIN, M_MAX, "m");
    inf.readEoln();

    for (int i = 0; i < m; i++) {
        int u = inf.readInt(1, n, "ui");
        inf.readSpace();

        int v = inf.readInt(1, n, "vi");
        inf.readSpace();

        ensuref(u != v, "The edge connects %d and %d nodes.", u, v);
        
        int w = inf.readInt(W_MIN, W_MAX, "wi");
        inf.readEoln();
    }

    int s = inf.readInt(1, n, "s");
    inf.readSpace();
    
    int t = inf.readInt(1, n, "t");   
    inf.readEoln();
    
    ensuref(s != t, "The Source and Destination must be different.", s, t);

    inf.readEof();
}
