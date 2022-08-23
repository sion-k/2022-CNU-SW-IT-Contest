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

vector<vector<int>> adj;

vector<int> a;
vector<int> r, b;

void dfs(int here, int prev) {
    if (a[here]) {
        r[here] = 1;
    } else {
        b[here] = 1;
    }
    for (int there : adj[here]) if (there != prev) {
        dfs(there, here);
        r[here] += r[there];
        b[here] += b[there];
    }
}

const int MOD = 1e9 + 7;
int sum_of_b;

vector<int> c;

void move(int here, int there) {
    r[here] -= r[there], b[here] -= b[there];
    r[there] += r[here], b[there] += b[here];
}

void construct(int here, int prev) {
    for (int there : adj[here]) {
        c[here] = (c[here] + (long long)r[there] * (sum_of_b - (a[here] == 0) - b[there])) % MOD;
    }
    for (int there : adj[here]) if (there != prev) {
        move(here, there);
        construct(there, here);
        move(there, here);
    }
}

int main() {
    FAST();
    int n;
    cin >> n;
    a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sum_of_b = n - accumulate(ALL(a), 0);
    adj = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    r = vector<int>(n + 1);
    b = vector<int>(n + 1);
    dfs(1, 1);
    int q;
    cin >> q;
    c = vector<int>(n + 1);
    construct(1, 1);
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << c[u] << "\n";
    }
}
