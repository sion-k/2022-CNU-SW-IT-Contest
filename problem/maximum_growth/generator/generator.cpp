#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int N_MIN = 1, N_MAX = 5000;
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

    int op2 = rnd.next(1, q);
    int op1 = q - op2;
    vector<int> op(q);
    for (int i = 0; i < op1; i++) {
        op[i] = 1;
    }
    for (int i = op1; i < q; i++) {
        op[i] = 2;
    }
    shuffle(ALL(op));

    for (int i = 0; i < q; i++) {
        int o = op[i];
        cout << o << " ";
        if (o == 1) {
            int k = rnd.next(1, n);
            int v = rnd.next(AI_MIN, AI_MAX);
            cout << k << " " << v;
        } else {
            int l = rnd.next(1, n);
            int r = rnd.next(l, n);
            cout << l << " " << r;
        }
        cout << "\n";
    }
}
