#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 10;
const int A_MIN = 1, A_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    int a = rnd.next(0, n);
    int b = n - a;
    cout << a << " " << b << "\n";
    for (int i = 0; i < n; i++) {
        cout << rnd.next(A_MIN, A_MAX) << " " << rnd.next(A_MIN, A_MAX) << "\n";
    }
}
