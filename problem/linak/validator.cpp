#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
const int N_MIN = 1, N_MAX = 1'000'000;
const int A_MIN = 1, A_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
    int a = inf.readInt(0, N_MAX, "a");
    inf.readSpace();
    int b = inf.readInt(0, N_MAX, "b");
    inf.readEoln();
    ensuref(a + b == n, "a + b must equals to n");
    for (int i = 0; i < n; i++) {
        int p = inf.readInt(A_MIN, A_MAX, "p");
        inf.readSpace();
        int q = inf.readInt(A_MIN, A_MAX, "q");
        inf.readEoln();
    }
    inf.readEof();
}
