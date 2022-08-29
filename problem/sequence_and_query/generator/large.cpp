#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int N_MIN = 4951, N_MAX = 5000;
const int AI_MIN = -1'000'000'000, AI_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        int ai = rnd.next(AI_MIN, AI_MAX);
        cout << ai << " \n"[i == n - 1];
    }
    
    int q = rnd.next(N_MIN, N_MAX);
    cout << q << "\n";

    for (int i = 0; i < q; i++) {
        int o = 2 - (i % 2);
        cout << o << " ";
        if (o == 1) {
            int k = rnd.next(1, n);
            int v = rnd.next(AI_MIN, AI_MAX);
            cout << k << " " << v;
        } else {
            int l = rnd.next(1, min(n, 10));
            int r = rnd.next(l, max(l, n - 10));
            cout << l << " " << r;
        }
        cout << "\n";
    }
}
