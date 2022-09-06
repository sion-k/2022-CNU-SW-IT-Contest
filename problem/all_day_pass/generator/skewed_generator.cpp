#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int N_MIN = 1, N_MAX = 100'000;
const int AI_MIN_1 = 1, AI_MAX_1 = 100;
const int AI_MIN_2 = 10'000'000, AI_MAX_2 = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i % 2 ? rnd.next(AI_MIN_1, AI_MAX_1) : rnd.next(AI_MIN_2, AI_MAX_2);
    }
    shuffle(ALL(a));
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
