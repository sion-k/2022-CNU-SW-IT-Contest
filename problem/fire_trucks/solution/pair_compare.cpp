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

// pq에서 가장 작은 짧은 간선, 같다면 가장 물을 많이 채울 수 있는 곳으로 이동
// 반례가 있을 것
struct compare {
    bool operator()(const tuple<long long, long long, int> u, tuple<long long, long long, int> v) {
        auto [u1, u2, u3] = u;
        auto [v1, v2, v3] = v;
        if (u1 == v1) {
            return u2 < v2;
        } else {
            return u1 > v1;
        }
    }
};

int n;
vector<int> a;

vector<vector<pair<int, int>>> adj;

const long long INF = 99'999LL * 1'000'000LL + 1;

vector<pair<long long, long long>> dijkstra(int start) {
    // dist[u] = u번 정점까지 최단 거리와 그 때 최대 물의 양
    vector<pair<long long, long long>> dist(n + 1, {INF, 0});
    priority_queue<tuple<long long, long long, int>, vector<tuple<long long, long long, int>>, compare> pq;

    dist[start] = { 0, a[start] };
    pq.emplace(0, a[start], start);

    while (!pq.empty()) {
        auto [hereDist, hereVolume, here] = pq.top();
        pq.pop();

        if (dist[here] < make_pair(hereDist, hereVolume)) continue;
        
        for (auto edge : adj[here]) {
            int there = edge.first;

            long long thereDist = hereDist + edge.second;
            long long thereVolume = hereVolume + a[there];

            pair<long long, long long> cand(thereDist, thereVolume);
            if (dist[there].first > cand.first || dist[there].first == cand.first && dist[there].second < cand.second) {
                dist[there] = cand;
                pq.emplace(thereDist, thereVolume, there);
            }
        }
    }
    return dist;
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

    vector<pair<long long, long long>> dist = dijkstra(s);
    
    if (dist[t].first == INF) {
        cout << -1 << "\n";
        return 0;
    }
    
    auto [retDist, retVolume] = dist[t];

    cout << retDist << " " << retVolume << "\n";
}
