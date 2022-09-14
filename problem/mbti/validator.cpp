#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100;

string mbti_ptrn = "[IE][NS][FT][PJ]";

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    string s = inf.readLine(mbti_ptrn, "s");

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
    
    for (int i = 0; i < n; i++) {
        string ti = inf.readLine(mbti_ptrn, "ti");
    }

    inf.readEof();
}
