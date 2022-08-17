#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) (int)((x).size())

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
vector<int> a, b;
vector<vector<int>> adj;
vector<vector<int>> children;
vector<int> cache;

void construct(int here, int prev) {
    for (int there : adj[here]) if (there != prev) {
        children[here].push_back(there);
        construct(there, here);
    }
}

int dp(int here) {
    if (cache[here]) return cache[here];
    int sum = a[here];
    for (int there : children[here]) {
        sum += dp(there);
    }
    return cache[here] = sum;
}

// (here, there) 간선을 지우고 방향을 바꿈
void reverse(int here, int there) {
    cache[here] -= cache[there];
    if (!b[there]) {
        b[there] = abs(cache[here] - cache[there]);
    }
    cache[there] += cache[here];
}

void dfs(int here, int prev) {
    for (int there : children[here]) if (there != prev) {
        reverse(here, there);
        dfs(there, here);
        reverse(there, here);
    }
}

/*
10
2 7 5 2 10 6 9 5 11 4
1 2
1 3
2 4
2 5
2 6
3 7
6 8
6 9
7 10
*/
int main() {
    cin >> n;
    a = vector<int>(n + 1);
    adj = vector<vector<int>>(n + 1);
    children = vector<vector<int>>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    construct(1, 1);
    b = vector<int>(n + 1);
    cache = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        dp(i);
    }
    dfs(1, 1);
    deb_tuple(b);
}
