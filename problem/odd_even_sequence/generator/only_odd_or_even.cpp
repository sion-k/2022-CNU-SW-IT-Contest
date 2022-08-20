#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100;
// 2를 곱해서 짝수를 만들거나, 2를 곱하고 1을 빼서 홀수로 만든다.
const int AI_HALF_MIN = 1, AI_HALF_MAX = 50;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    bool parity = rnd.next(0, 1);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        int ai = 2 * rnd.next(AI_HALF_MIN, AI_HALF_MAX) - parity;
        cout << ai << " \n"[i == n - 1];
    }
}
