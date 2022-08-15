#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 99'990, N_MAX = 100'000;
const int AI_MIN = 999'999'990, AI_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = N_MAX;
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << rnd.next(AI_MIN, AI_MAX) << " \n"[i == n - 1];
    }
}
