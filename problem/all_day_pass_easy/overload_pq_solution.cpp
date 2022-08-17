#include <bits/stdc++.h>

using namespace std;

// pq에 0인 원소를 유지하는 풀이입니다. 조금 느립니다.
int main() {
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
    while (true) {
        auto [v, i] = pq.top();
        pq.pop();
        if (v == 0) break;
        if (prev == i) {
            if (pq.empty()) break;
            auto [nv, ni] = pq.top();
            pq.pop();
            if (nv == 0) break;
            nv--;
            prev = ni;
            pq.emplace(nv, ni);
        } else {
            v--;
            prev = i;
        }
        pq.emplace(v, i);
        sum++;
    }
    cout << sum << "\n";
}
