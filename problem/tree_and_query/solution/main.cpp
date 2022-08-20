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
vector<pair<int, int>> b;

vector<vector<int>> adj;

int dfs1(int here, int prev) {
    a[here] = 1;
    for (int there : adj[here]) if (there != prev) {
        a[here] += dfs1(there, here);
    }
    return a[here];
}

// (here, there) 간선을 지우고 방향을 바꿈
void reverse(int here, int there) {
    a[here] -= a[there];
    b[there].first = max(b[there].first, a[here]);
    b[there].second = min(b[there].second, a[here]);
    a[there] += a[here];
}

void dfs2(int here, int prev) {
    for (int there : adj[here]) if (there != prev) {
        reverse(here, there);
        dfs2(there, here);
        reverse(there, here);
    }
}

int main() {
    FAST();
    cin >> n >> q;
    a = vector<int>(n + 1);
    b = vector<pair<int, int>>(n + 1, { 1, n });
    adj = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << b[u].first << " " << b[u].second << "\n";
    }
}
