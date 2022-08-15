#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 10;
const int AI_MIN = 1, AI_MAX = 10;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << rnd.next(AI_MIN, AI_MAX) << " \n"[i == n - 1];
    }
}
