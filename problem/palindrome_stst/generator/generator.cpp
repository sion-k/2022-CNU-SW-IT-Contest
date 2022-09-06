#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// n=1..5까지는 모든 경우의 수 생성
const int N_MIN = 6, N_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        int s = rnd.next(0, 1);
        if (s) {
            cout << "s";
        } else {
            cout << "t";
        }
    }
    cout << "\n";
}
