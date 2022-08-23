#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()

using namespace std;

// a는 n + 1 길이의 정렬된 배열.
// a[p] = m이라고 가정했을 때, 스파이가 유일하면 그 스파이의 번호
int solve(int n, int p, vector<int> &a) {
    int m = a[p], x = 0, k = 0;
    for (int i = 0; i < n + 1; i++) {
        if (a[i] == x + m) {
            x += m;
        } else {
            k = a[i];
        }
    }
    return (x == n * m) && (k % m) ? k : 0;
}

const int N_MIN = 2, N_MAX = 100'000;
const int M_MIN = 2, M_MAX = 100'000;
const int AI_MIN = 2, AI_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
    vector<int> a = inf.readInts(n + 1, AI_MIN, AI_MAX, "a");
    inf.readEoln();
    inf.readEof();
    
    sort(ALL(a));
    int zro = solve(n, 0, a), one = solve(n, 1, a);
    ensuref((zro > 0) ^ (one > 0), "zro=%d, one=%d the answer must be exists and unique", zro, one);

    int m = solve(n, 0, a) ? a[0] : a[1];
    ensuref(M_MIN <= m && m <= M_MAX, "m=%d must be in range [%d..%d]", m, M_MIN, M_MAX);

    int k = zro + one;
    ensuref(k % m, "k=%d must be not divisible by m=%d", k, m);
    
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        b.push_back(i * m);
    }
    vector<int> c;
    for (int i = 0; i < n + 1; i++) {
        if (a[i] % m == 0) {
            c.push_back(a[i]);
        }
    }
    ensuref(b == c, "%d, 2 * %d, ... %n * %d must occur only once", m, m, n, m);
    
}
