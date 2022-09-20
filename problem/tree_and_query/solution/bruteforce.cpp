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

vector<vector<int>> p;

vector<long long> c;

// start 정점에서 시작하는 길이 3 이상의 단순 경로 모두 반환
// a[start] != a[end] 여야 한다.
void dfs(int here, int prev, vector<int> path) {
    path.push_back(here);
    for (int there : adj[here]) if (there != prev) {
        dfs(there, here, path);
    }
    if (SIZE(path) >= 3 && a[path[0]] != a[here]) {
        p.push_back(path);
    }
    path.pop_back();
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
    for (int here = 1; here <= n; here++) {
        dfs(here, here, vector<int>());
    }

    c = vector<long long>(n + 1);
    for (auto& e : p) {
        for (int i = 1; i < SIZE(e) - 1; i++) {
            c[e[i]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        c[i] /= 2;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << c[u] << "\n";
    }
}
