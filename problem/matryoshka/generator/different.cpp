#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// 모든 수가 달라서 정답이 1인 데이터
const int N_MIN = 1, N_MAX = 1'000;
const int AI_MIN = 1, AI_MAX = 1e9;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";

    set<int> s;

    for (int i = 0; i < n; i++) {
        int ai = rnd.next(AI_MIN, AI_MAX);
        if (s.find(ai) != s.end()) {
            i--;
            continue;
        }
        s.insert(ai);
        cout << ai << " \n"[i == n - 1];
    }
}
