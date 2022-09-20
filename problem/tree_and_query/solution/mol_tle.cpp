#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, a[101010];
ll b[101010], r[101010], sumb, sumr;
vector<int> adj[101010], chd[101010];

void dfs(int v, int prv) {
    if (a[v]) r[v] = 1, sumr++;
    else b[v] = 1, sumb++;

    for (auto& i : adj[v]) {
        if (i == prv) continue;

        dfs(i, v);
        chd[v].push_back(i);
        r[v] += r[i];
        b[v] += b[i];
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    int q; cin >> q;
    while (q--) {
        int v; cin >> v;

        ll ret = 0;

        ll pb = b[1] - b[v], pr = r[1] - r[v];
        ret += pb * (sumr - pr - a[v]);
        for (auto& i : chd[v]) {
            ret += b[i] * (sumr - r[i] - a[v]);
        }

        cout << ret << '\n';
    }

    return 0;
}
