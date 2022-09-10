#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 2, N_MAX = 100'000;
const int AI_MIN = 1, AI_MAX = 1'000'000;

const int M_MIN = 1, M_MAX = 300'000;
const int W_MIN = 1, W_MAX = 1'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    
    for (int i = 1; i <= n; i++) {
        int ai = rnd.next(AI_MIN, AI_MAX);
        cout << ai << " \n"[i == n];
    }

    int m = rnd.next(M_MIN, M_MAX);
    cout << m << "\n";

    for (int i = 0; i < m; i++) {
        int ui = rnd.next(1, n);
        int vi = rnd.next(1, n);

        if (ui == vi) {
            i--;
            continue;
        }
        
        int wi = rnd.next(1, W_MAX);

        cout << ui << " " << vi << " " << wi << "\n";
    }

    int s = rnd.next(1, n - 1);
    int t = rnd.next(s + 1, n);

    if (rnd.next(0, 1)) {
        swap(s, t);
    }

    cout << s << " " << t << "\n";
}
