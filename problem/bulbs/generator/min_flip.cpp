#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// 모두 켜져있기 때문에 가장 작은걸 뒤집어야 하는 데이터
const int N_MIN = 1, N_MAX = 200'000;
const int AI_MIN = 1, AI_MAX = 5'000;
const int BI_MIN = 1, BI_MAX = 1;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        int ai = rnd.next(AI_MIN, AI_MAX);
        cout << ai << " \n"[i == n - 1];
    }

    for (int i = 0; i < n; i++) {
        int bi = rnd.next(BI_MIN, BI_MAX);
        cout << bi << " \n"[i == n - 1];
    }
    
}
