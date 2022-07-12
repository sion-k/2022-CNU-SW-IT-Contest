#include <bits/stdc++.h>
#define SIZE(x) (int)((x).size())
#define FAST() cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    FAST();
    string s;
    cin >> s;
    int n = SIZE(s);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = s[i] == '(' ? 1 : -1;
        if (i - 1 >= 0) {
            p[i] += p[i - 1];
        }
    }
    vector<int> left_min(n), right_min(n);
    for (int i = 0; i < n; i++) {
        left_min[i] = p[i];
        if (i - 1 >= 0) {
            left_min[i] = min(left_min[i], left_min[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        right_min[i] = p[i];
        if (i + 1 < n) {
            right_min[i] = min(right_min[i], right_min[i + 1]);
        }
    }
    int ret = 0;
    if (p[n - 1] == 2) {
        for (int here = 0; here < n; here++) {
            if (s[here] == '(' && left_min[here] >= 0 && p[here] >= 2 && (here == n - 1 || right_min[here + 1] >= 2)) {
                ret++;
            }
        }
    } else if (p[n - 1] == -2) {
        for (int here = 0; here < n; here++) {
            int sum = p[n - 1];
            if (here - 1 >= 0) sum -= p[here - 1];
            if (s[here] == ')' && (here == 0 || left_min[here - 1] >= 0) && sum <= -2) {
                ret++;
            }
        }
    }
    cout << ret << "\n";
}
