#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 10;
const int T_MIN = -1'000, T_MAX = 1'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    int t = rnd.next(T_MIN, T_MAX);

    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        int ai = rnd.next(0, 1);
        cout << ai << " \n"[i == n - 1];
    }

    vector<int> p(n);
    /* setup parents for vertices 1..n-1 */
    for (int i = 1; i <= n - 1; i++) {
        p[i] = rnd.wnext(i, t);
    }

    /* shuffle vertices 1..n-1 */
    vector<int> perm(n);
    for (int i = 1; i <= n - 1; i++) {
        perm[i] = i;
    }

    shuffle(perm.begin() + 1, perm.end());

    /* put edges considering shuffled vertices */
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
        if (rnd.next(2)) {
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        } else {
            edges.push_back(make_pair(perm[p[i]], perm[i]));
        }
    }

    for (auto& e : edges) {
        cout << e.first + 1 << " " << e.second + 1 << "\n";
    }

    int q = rnd.next(1, n);
    cout << q << "\n";

    for (int i = 0; i < q; i++) {
        int u = rnd.next(1, n);
        cout << u << "\n";
    }
}
