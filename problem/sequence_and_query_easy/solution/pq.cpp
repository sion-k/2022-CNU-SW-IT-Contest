#include <bits/stdc++.h>

using namespace std;

int query(int n, vector<int>& a, int l, int r) {
    int max = 0;
    priority_queue<int> pq;
    for (int i = l; i <= r; i++) {
        pq.emplace(-a[i]);
        max = ::max(max, a[i] + pq.top());
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int o;
        cin >> o;
        if (o == 1) {
            int k, v;
            cin >> k >> v;
            a[k - 1] = v;
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(n, a, l - 1, r - 1) << "\n";
        }
    }
}
