#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) (int)((x).size())
#define OPEN(t) freopen("data.txt", (t), (t == "r" ? stdin : stdout))
#define FAST() cin.tie(0)->sync_with_stdio(0)
#define deb(x) cout << #x << " : " << (x) << "\n"
#define deb_pair(x, y)                                                         \
    cout << "(" << #x << ", " << #y << ") : (" << (x) << ", " << (y) << ")\n"
#define deb_triplet(x, y, z)                                                   \
    cout << "(" << #x << ", " << #y << ", " << #z << ") : (" << (x) << ", "    \
         << (y) << ", " << (z) << ")\n"
#define deb_tuple(s)                                                           \
    for (int i = 0; i < SIZE(s); i++)                                          \
        cout << s[i] << " \n"[i == SIZE(s) - 1];
using namespace std;

long long sum(int n, int mask, vector<int>& a) {
    long long sum = 0;
    for (int i = 0; i < n; i++) if (mask & (1 << i)) {
        sum += a[i];
    }
    return sum;
}

long long left_sum(int n, int s, int mask, vector<int> &a) {
    vector<int> b;
    for (int i = 0; i < n; i++) if (!(mask & (1 << i))) {
        b.push_back(a[i]);
    }
    sort(ALL(b));
    reverse(ALL(b));
    return accumulate(b.begin(), b.begin() + min(s, SIZE(b)), 0);
}

int main() {
    FAST();
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    long long max = 0;
    for (int mask = 0; mask < (1 << n); mask++) if (__builtin_popcount(mask) <= m) {
        long long cand = sum(n, mask, a) + left_sum(n, s, mask, b);
        max = ::max(max, cand);
    }
    cout << max << "\n";
}
