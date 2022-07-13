#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, int k){
    return (n%m!=0) ?  (n/m) * k + k : (n/m)*k;
}

int n, m, k;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    cout << solve(n, m, k) << '\n';
}
