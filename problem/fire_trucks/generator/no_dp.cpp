#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 2, N_MAX = 100'000;
const int AI_MIN = 1, AI_MAX = 1'000'000;

const int M_MIN = 1, M_MAX = 300'000;
const int W_MIN = 1, W_MAX = 1'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = N_MAX;
    cout << n << "\n";
    
    for (int i = 1; i <= n; i++) {
        int ai = rnd.next(AI_MIN, AI_MAX);
        cout << ai << " \n"[i == n];
    }

    int m = M_MAX;
    cout << m << "\n";

    // 모든 간선의 가중치가 같고 중복 간선이 존재함
    int wi = rnd.next(W_MIN, W_MAX);
    
    for (int i = 0; i <= 2 * N_MAX; i++) {
        int ui = rnd.next(1, n - 1);
        int vi = ui + 1;
        cout << ui << " " << vi << " " << wi << "\n";
    }

    for (int i = 1; i <= N_MAX - 1; i++) {
        int ui = i;
        int vi = ui + 1;
        cout << ui << " " << vi << " " << wi << "\n";
    }

    int s = 1;
    int t = n;

    if (rnd.next(0, 1)) {
        swap(s, t);
    }

    cout << s << " " << t << "\n";
}
