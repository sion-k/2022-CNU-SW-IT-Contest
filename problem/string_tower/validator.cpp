#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100;
const int M_MIN = 1, M_MAX = 100;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readSpace();
    int m = inf.readInt(M_MIN, M_MAX, "m");
    inf.readEoln();

    string ptrn = "[a-z]{" + to_string(m) + "}";
    
    for (int i = 0; i < n; i++) {
        string si = inf.readLine(ptrn, "si");
    }

    inf.readEof();
}
