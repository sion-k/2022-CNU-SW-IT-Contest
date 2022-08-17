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

int main() {
    FAST();
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> q[i];
    }
    long long max = 0;
    for (int i = 0; i < (1 << n); i++) if (__builtin_popcount(i) == a) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += p[j];
            } else {
                sum += q[j];
            }
        }
        max = ::max(max, sum);
    }
    cout << max << "\n";
}
