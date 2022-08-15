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

int n;
string s;
vector<vector<int>> cache;

const string mbti = "IESNTFJP";
const int null = -4;

int dp(int here, int pick) {
    if (here == n) return pick ? -pick : 0;
    if (cache[here][pick] != null) return cache[here][pick];
    int max = dp(here + 1, pick);
    if (mbti.find(s[here]) / 2 == pick) {
        max = ::max(max, 1 + dp(here + 1, (pick + 1) % 4));
    }
    return cache[here][pick] = max;
}

int main() {
    FAST();
    cin >> n >> s;
    cache = vector<vector<int>>(n, vector<int>(4, null));
    cout << dp(0, 0) << "\n";
}
