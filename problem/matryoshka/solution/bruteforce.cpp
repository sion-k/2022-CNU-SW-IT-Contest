#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

vector<ll> vec;

int main(void) {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vec.resize(n, 0);
    for (int i = 0; i < n;i++) {
        cin >> vec[i];
    }
    int ret = -1;
    for (int i = 0;i < n;i++) {
        int cnt = 1;
        for (int j = 0;j < n;j++) {
            if (i == j) continue;
            if (vec[i] == vec[j]) cnt++;
        }
        if (ret < cnt) ret = cnt;
    }
    cout << ret << endl;
}
