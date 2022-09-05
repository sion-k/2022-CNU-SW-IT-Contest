#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) (int)((x).size())

using namespace std;

// 두 범위에 포함된 소수의 개수가 같은 데이터
const int RNAGE_MIN = 2, RANGE_MAX = 1'000;

// 2부터 1000까지 소수의 개수
const int PRIME_COUNT = 168;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    // 소수 계량 누적 합
    vector<int> p(1001);
    for (int i = 2; i <= 1000; i++) {
        p[i] += p[i - 1];
        if (is_prime(i)) {
            p[i]++;
        }
    }

    // 겹치는 구간
    int c = rnd.next(RNAGE_MIN, RANGE_MAX);
    int b = rnd.next(c, RANGE_MAX);
    int a = c, d = b;

    // 왼쪽 범위와 오른쪽 범위의 소수 개수 중 최소
    // 그 중에서 랜덤으로 고른다.
    int cnt = rnd.next(0, min(p[RANGE_MAX] - p[b], p[c - 1]));

    while (p[c - 1] - p[a - 1] != cnt) {
        a--;
    }

    while (p[d] - p[b] != cnt) {
        d++;
    }

    pair<int, int> yt({ a, b });
    pair<int, int> yj({ c, d });

    if (rnd.next(0, 1)) {
        swap(yt, yj);
    }

    cout << yt.first << " " << yt.second << "\n";
    cout << yj.first << " " << yj.second << "\n";
}
