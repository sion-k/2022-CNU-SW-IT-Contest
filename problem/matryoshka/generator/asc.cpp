#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// 오름차순 데이터
const int N_MIN = 1, N_MAX = 1'000;
const int AI_MIN = 1, AI_MAX = 1e9;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = rnd.next(AI_MIN, AI_MAX);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
