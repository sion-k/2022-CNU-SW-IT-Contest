#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100'000;
const int AI_MIN = -1'000'000'000, AI_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();

    vector<int> a = inf.readInts(n, AI_MIN, AI_MAX, "a");
    inf.readEoln();

    int q = inf.readInt(N_MIN, N_MAX, "q");
    inf.readEoln();

    bool query2 = false;
    for (int i = 0; i < q; i++) {
        int o = inf.readInt(1, 2, "o");
        inf.readSpace();

        if (o == 1) {
            int k = inf.readInt(1, n, "k");
            inf.readSpace();
            int v = inf.readInt(AI_MIN, AI_MAX, "v");
        } else {
            query2 = true;
            int l = inf.readInt(1, n, "l");
            inf.readSpace();
            int v = inf.readInt(l, n, "r");
        }
        inf.readEoln();
    }
    inf.readEof();

    ensuref(query2, "Input should contain at least one 2 type query");
}
