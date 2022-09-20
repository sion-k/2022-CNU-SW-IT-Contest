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

vector<int> a;

vector<vector<int>> adj;

// 빨간 정점과 파란 정점의 개수 반환
pair<int, int> dfs(int here, int prev) {
    pair<int, int> ret;
    if (a[here]) ret.first++;
    else ret.second++;

    for (int there : adj[here]) if (there != prev) {
        pair<int, int> cand = dfs(there, here);
        ret.first += cand.first;
        ret.second += cand.second;
    }
    return ret;
}

int main() {
    FAST();
    int n;
    cin >> n;
    a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    adj = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int here;
        cin >> here;

        vector<pair<int, int>> children;
        for (int there : adj[here]) {
            children.push_back(dfs(there, here));
        }

        int b_sum = 0;
        for (auto& ch : children) {
            b_sum += ch.second;
        }

        long long ret = 0;
        for (auto& ch : children) {
            ret += (long long)ch.first * (b_sum - ch.second);
        }
        cout << ret << "\n";
    }
}
