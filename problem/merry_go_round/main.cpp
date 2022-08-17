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

int solve(int n, queue<int> &q) {
    int cost = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int x = q.front();
        q.pop();
        q.push(x);
        cost += abs(sum);
        sum += x - 1;
    }
    return cost;
}

int main() {
    FAST();
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    int min = solve(n, q);
    for (int i = 0; i < n; i++) {
        int x = q.front();
        q.pop();
        q.push(x);
        min = ::min(min, solve(n, q));
    }
    cout << min << "\n";
}
