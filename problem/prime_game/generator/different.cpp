#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) (int)((x).size())

using namespace std;

// 범위가 서로 겹치지 않고 한 쪽 범위가 나머지 한 쪽 범위보다 소수의 개수가 1개 많은 데이터
const int RANGE_MIN = 2, RANGE_MAX = 400;

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

// 두 구간이 서로 겹치는지 확인
bool overlaps(pair<int, int> u, pair<int, int> v) {
    if (u.first <= v.first && v.second <= u.second) return true;
    if (u.second < v.first || v.second < u.first) return false;
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

    // 소수의 개수 별로 구간을 모두 저장
    vector<vector<pair<int, int>>> range(PRIME_COUNT + 1);
    for (int i = RANGE_MIN; i <= RANGE_MAX; i++) {
        for (int j = i; j <= RANGE_MAX; j++) {
            int cnt = p[j] - p[i - 1];
            range[cnt].emplace_back(i, j);
        }
    }

    // (half, half + 1)개씩 소수가 포함되게 한다
    int half = rnd.next(0, PRIME_COUNT / 2 - 1);

    // 서로 겹치지 않는 구간 쌍을 모두 가져온다.
    vector<tuple<int, int, int, int>> cand;
    for (int i = 0; i < SIZE(range[half]); i++) {
        for (int j = i; j < SIZE(range[half + 1]); j++) {
            if (!overlaps(range[half][i], range[half + 1][j])) {
                auto [a, b] = range[half][i];
                auto [c, d] = range[half + 1][j];
                cand.emplace_back(a, b, c, d);
            }
        }
    }

    auto [a, b, c, d] = rnd.any(cand);
    pair<int, int> yt({ a, b });
    pair<int, int> yj({ c, d });

    if (rnd.next(0, 1)) {
        swap(yt, yj);
    }

    cout << yt.first << " " << yt.second << "\n";
    cout << yj.first << " " << yj.second << "\n";
}
