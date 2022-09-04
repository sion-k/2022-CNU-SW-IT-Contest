#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int N_MIN = 1, N_MAX = 200'000;
const int AI_MIN = 1, AI_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rnd.next(AI_MIN, AI_MAX);
    }

    sort(ALL(a));
    reverse(ALL(a));
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
