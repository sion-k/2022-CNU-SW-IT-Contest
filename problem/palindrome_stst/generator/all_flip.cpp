#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// n=1..5까지는 모든 경우의 수 생성
const int N_MIN = 90, N_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    int left = rnd.next(0, 1);
    int right = !left;
    for (int i = 0; i < n / 2; i++) {
        cout << (left ? "s" : "t");
    }
    for (int i = n / 2; i < n; i++) {
        cout << (right ? "s" : "t");
    }
    cout << "\n";
}
