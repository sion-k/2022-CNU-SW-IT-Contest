#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()

using namespace std;

// a는 n + 1 길이의 정렬된 배열.
// a[p] = m이라고 가정했을 때, m의 배수가 n개인지만 확인하는 풀이
int solve(int n, int p, vector<int> &a) {
    int m = a[p], cnt = 0, k = 0;
    for (int i = 0; i < n + 1; i++) {
        if (a[i] % m == 0) {
            cnt++;
        } else {
            k = a[i];
        }
    }
    return cnt == n ? k : 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (auto &x : a) {
        cin >> x;
    }
    sort(ALL(a));
    int k = solve(n, 0, a) ^ solve(n, 1, a);
    cout << k << "\n";
}
