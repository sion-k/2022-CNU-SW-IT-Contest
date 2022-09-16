#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// 모든 수가 같은 데이터 max
const int N_MIN = 1'000, N_MAX = 1'000;
const int AI_MIN = 1e9, AI_MAX = 1e9;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";

    int ai = rnd.next(AI_MIN, AI_MAX);

    for (int i = 0; i < n; i++) {
        cout << ai << " \n"[i == n - 1];
    }
}
