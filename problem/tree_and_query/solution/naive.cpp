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

vector<int> a;
vector<vector<int>> adj;

void dfs(int here, int prev) {
    for (int there : adj[here]) if (there != prev) {
        dfs(there, here);
        a[here] += a[there];
    }
}

int main() {
    FAST();
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        a = vector<int>(n + 1, 1);
        dfs(u, u);
        int max = 1, min = n;
        for (int there : adj[u]) {
            max = ::max(max, a[there]);
            min = ::min(min, a[there]);
        }
        cout << max << " " << min << "\n";
    }
}
