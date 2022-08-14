#include <bits/stdc++.h>
#define FAST() cin.tie(0)->sync_with_stdio(0)

using namespace std;

void fool(priority_queue<pair<int, int>>& pq) {
    if (pq.empty()) return;
    auto x = pq.top();
    pq.pop();
    pq.push(x);
}

int main() {
    FAST();
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++){
        pq.emplace(a[i], i);
    }
    int prev = -1;
    int sum = 0;
    while (!pq.empty()) {
        auto [v, i] = pq.top();
        pq.pop();
        if (prev == i) {
            if (pq.empty()) break;
            auto [nv, ni] = pq.top();
            pq.pop();
            nv--;
            prev = ni;
            if (nv > 0) {
                pq.emplace(nv, ni);
            }
        } else {
            v--;
            prev = i;
        }
        if (v > 0) {
            pq.emplace(v, i);
        }
        fool(pq);
        sum++;
    }
    cout << sum << "\n";
}
