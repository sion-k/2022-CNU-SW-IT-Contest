#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) (int)((x).size())
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

int n, q;
vector<int> cache;

vector<vector<int>> adj;
vector<vector<int>> children;

int main() {
    FAST();
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    children = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << b[u].first << " " << b[u].second << "\n";
    }
}
