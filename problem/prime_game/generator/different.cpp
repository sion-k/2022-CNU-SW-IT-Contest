#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) (int)((x).size())

using namespace std;

// 범위가 서로 겹치지 않고 한 쪽 범위가 나머지 한 쪽 범위보다 소수의 개수가 1개 많은 데이터
const int RANGE_MIN = 2, RANGE_MAX = 1'000;

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

// p[i], p[j] 는 양쪽 끝이 소수인 구간
// 적당히 포함된 소수의 개수가 변하지 않도록 늘린다.
pair<int, int> spread(vector<int> &p, int i, int j) {
    pair<int, int> ret;
    ret.first = rnd.next(i == 0 ? 1 : p[i - 1] + 1, p[i]);
    ret.second = rnd.next(p[j], j == PRIME_COUNT - 1 ? p[j] : p[j + 1] - 1);
    return ret;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    // 소수
    vector<int> p;
    for (int i = 2; i <= 1000; i++) {
        if (is_prime(i)) {
            p.push_back(i);
        }
    }

    // length, length + 1 길이의 구간을 두 개 고른다
    int length = rnd.next(0, PRIME_COUNT - 2);
    int a = rnd.next(0, PRIME_COUNT - length - 1);
    int b = a + length;
    int c = rnd.next(0, PRIME_COUNT - (length + 1) - 1);
    int d = c + length + 1;

    pair<int, int> yt = spread(p, a, b);
    pair<int, int> yj = spread(p, c, d);

    if (rnd.next(0, 1)) {
        swap(yt, yj);
    }

    cout << yt.first << " " << yt.second << "\n";
    cout << yj.first << " " << yj.second << "\n";
}
