#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()

using namespace std;

// 쿼리에 대한 정답이 10^9에 가까운 값인 데이터
const int N_MIN = 1, N_MAX = 200'000;
const int AI_MIN = 1, AI_MAX = 1'000'000'000;
const int VAR = 1'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        int large = rnd.next(0, 1);
        int ai = large ? rnd.next(AI_MAX - VAR, AI_MAX) : rnd.next(AI_MIN, VAR);
        cout << ai << " \n"[i == n - 1];
    }
    
}
