#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;

const int N_MIN = 1, N_MAX = 300'000;
const int AB_MIN = 1, AB_MAX = 100'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readSpace();
    int m = inf.readInt(0, n, "m");
    inf.readSpace();
    int s = inf.readInt(0, n, "s");
    inf.readEoln();
    ensuref(m + s <= n, "m + s <= n");
    for (int i = 0; i < n; i++) {
        int a = inf.readInt(AB_MIN, AB_MAX, "a");
        inf.readSpace();
        int b = inf.readInt(AB_MIN, AB_MAX, "b");
        inf.readEoln();
    }
    inf.readEof();
}
