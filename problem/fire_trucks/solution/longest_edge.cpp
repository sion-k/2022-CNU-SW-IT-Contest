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
vector<int> a;

vector<vector<pair<int, int>>> adj;

const long long INF = 99'999LL * 1'000'000LL + 1;

vector<long long> dijkstra(int start) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [hereCost, here] = pq.top();
        // hereCost = -hereCost;
        pq.pop();

        if (dist[here] < hereCost) continue;

        for (auto edge : adj[here]) {
            int there = edge.first;
            long long thereCost = hereCost + edge.second;
            if (dist[there] > thereCost) {
                dist[there] = thereCost;
                pq.emplace(thereCost, there);
                // ........~~~~~~~~~
            }
        }
    }
    return dist;
}

vector<long long> cache;

long long dp(int here, vector<long long> &dist) {
    if (cache[here]) return cache[here];
    long long max = 0;
    for (auto edge : adj[here]) {
        int there = edge.first;
        long long cost = edge.second;
        if (dist[here] - cost == dist[there]) {
            max = ::max(max, dp(there, dist));
        }
    }
    return cache[here] = a[here] + max;
}

int main() {
    FAST();

    cin >> n;
    
    a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    adj = vector<vector<pair<int, int>>>(n + 1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int s, t;
    cin >> s >> t;

    vector<long long> dist = dijkstra(t);
    
    if (dist[s] == INF) {
        cout << -1 << "\n";
        return 0;
    }
    
    cache = vector<long long>(n + 1);
    cout << dist[s] << " " << dp(s, dist) << "\n";
}
