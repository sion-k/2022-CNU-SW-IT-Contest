#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) (int)((x).size())

using namespace std;

// 가능한 모든 구간에 대해서 물어보는 데이터
// 물어보면서 계속 임의의 위치의 값을 바꾼다
const int N_MIN = 1, N_MAX = 50;
const int Q_MAX = 5'000;
const int AI_MIN = -10, AI_MAX = 10;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        int ai = 0;
        cout << ai << " \n"[i == n - 1];
    }
    
    vector<tuple<int, int, int>> query;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            query.emplace_back(2, i, j);
        }
    }

    int q = 2 * SIZE(query);
    cout << q << "\n";

    while (SIZE(query) < q) {
        int k = rnd.next(1, n);
        int v = rnd.next(AI_MIN, AI_MAX);
        query.emplace_back(1, k, v);
    }

    shuffle(ALL(query));
    
    for (int i = 0; i < q; i++) {
        auto [q1, q2, q3] = query[i];
        cout << q1 << " " << q2 << " " << q3 << "\n";
    }
}
