#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define FAST() cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
    FAST();
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int max_a = *max_element(ALL(a));
    int prev = -1;
    int sum = 0;
    while (true) {
        pair<int, int> max;
        for (int i = 0; i < n; i++) if (i != prev) {
            max = ::max(max, {a[i], i});
            if (max.first == max_a) {
                break;
            }
        }
        if (max.first == 0) break;
        a[max.second]--;
        sum++;
        prev = max.second;
    }
    cout << sum << "\n";
}
