#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()

using namespace std;

// n이 홀수이고, 홀수 개수가 하나 더 많은 수열
// 무조건 1이 정답인 데이터입니다.
const int N_MIN = 1, N_MAX = 50;
const int AI_HALF_MIN = 1, AI_HALF_MAX = 50;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = 2 * rnd.next(N_MIN, N_MAX) - 1;
    cout << n << "\n";
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        a[i - 1] = 2 * rnd.next(AI_HALF_MIN, AI_HALF_MAX) - (i % 2);
    }
    shuffle(ALL(a));
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
