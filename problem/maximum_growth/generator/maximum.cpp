#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()

using namespace std;

// 대부분 비슷한 수로 이루어진 수열
const int N_MIN = 200'000, N_MAX = 200'000;
const int AI_MIN = 1, AI_MAX = 1'000'000'000;
const int RANGE_MIN = 0, RANGE_MAX = 1'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    int center = rnd.next(AI_MIN, AI_MAX);
    int range = rnd.next(RANGE_MIN, RANGE_MAX);
    for (int i = 0; i < n; i++) {
        int ai = rnd.next(max(AI_MIN, center - range), min(AI_MAX, center + range));
        cout << ai << " \n"[i == n - 1];
    }
    
}
