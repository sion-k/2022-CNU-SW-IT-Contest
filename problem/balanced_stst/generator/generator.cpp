#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// n=1..8까지는 모든 경우의 수 생성
const int N_MIN = 9, N_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    for (int i = 0; i < n - 2; i++) {
        int s = rnd.next(0, 1);
        if (s) {
            cout << "s";
        } else {
            cout << "t";
        }
    }
    int right = rnd.next(0, 1);
    if (right) {
        cout << "st";
    } else {
        cout << "ts";
    }
    cout << "\n";
}
