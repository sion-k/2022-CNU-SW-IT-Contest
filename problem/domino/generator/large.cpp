#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 991, N_MAX = 1'000;
const int AI_MIN = 990'000, AI_MAX = 1'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        int ai = rnd.next(AI_MIN, AI_MAX);
        cout << ai << " \n"[i == n - 1];
    }
}
