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
    int max = *max_element(ALL(a));
    long long sum = accumulate(ALL(a), 0LL);
    long long res = sum - max;
    long long ret = (max > res) ? 2 * res + 1 : sum;
    cout << ret << "\n";
}
