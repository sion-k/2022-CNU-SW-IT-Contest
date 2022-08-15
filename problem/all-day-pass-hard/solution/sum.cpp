#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int max = *max_element(ALL(a));
    long long sum = accumulate(ALL(a), 0LL);
    long long res = sum - max;
    long long ret = (max >= res) ? 2 * res + 1 : sum;
    cout << ret << "\n";
}
