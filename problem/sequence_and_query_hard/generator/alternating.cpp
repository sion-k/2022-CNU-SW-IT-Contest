#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()

using namespace std;

// 0과 1 중에 대부분 하나로만 이루어진 수열에서
// 쿼리를 통해서 하나씩 추가
// 2번 쿼리는 매우 좁은 범위로 들어옴
const int N_MAX = 100'000;
const int AI_MIN = 0, AI_MAX = 1;
const int RANGE_MIN = 0, RANGE_MAX = 10;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = N_MAX;
    cout << n << "\n";
    int ai = rnd.next(AI_MIN, AI_MAX);
    for (int i = 0; i < n; i++) {
        int o = rnd.next(1, 100);
        if (o <= 4) {
            cout << !ai << " \n"[i == n - 1];
        } else {
            cout << ai << " \n"[i == n - 1];
        }
    }
    
    int q = N_MAX;
    cout << q << "\n";

    for (int i = 0; i < q; i++) {
        int o = rnd.next(1, 100);
        if (o <= 4) {
            int k = rnd.next(1, n);
            int v = !ai;
            cout << "1" << " " << k << " " << v;
        } else {
            int range = rnd.next(RANGE_MIN, RANGE_MAX);
            int l = rnd.next(1, n - range);
            int r = l + range;
            cout << "2" << " " << l << " " << r;
        }
        cout << "\n";
    }
}
