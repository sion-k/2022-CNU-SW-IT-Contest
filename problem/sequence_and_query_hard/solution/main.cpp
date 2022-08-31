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

class Segment_tree {
public:
    // min, max, ret
    vector<tuple<int, int, int>> t;

    const int INF = 1e9 + 1;

    Segment_tree(int n, vector<int> &a) {
        t = vector<tuple<int, int, int>>(4 * n);
        init(1, 0, n - 1, a);
    }

    tuple<int, int, int> combine(tuple<int, int, int> l, tuple<int, int, int> r) {
        auto [left_min, left_max, left_ret] = l;
        auto [right_min, right_max, right_ret] = r;
        int min = ::min(left_min, right_min);
        int max = ::max(left_max, right_max);
        int ret = ::max(left_ret, right_ret);
        if (right_max != -INF && left_min != INF) {
            ret = ::max(ret, right_max - left_min);
        }
        return { min, max, ret };
    }

    void init(int v, int l, int r, vector<int> &a) {
        if (l == r) {
            t[v] = { a[l], a[l], 0 };
        } else {
            int m = (l + r) / 2;
            init(2 * v, l, m, a);
            init(2 * v + 1, m + 1, r, a);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    void update(int v, int l, int r, int k, int x) {
        if (l == r) {
            t[v] = { x, x, 0 };
        } else {
            int m = (l + r) / 2;
            if (k <= m) {
                update(2 * v, l, m, k, x);
            } else {
                update(2 * v + 1, m + 1, r, k, x);
            }
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    tuple<int, int, int> query(int v, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return t[v];
        }
        if (qr < l || r < ql) {
            return { INF, -INF, 0 };
        }
        int m = (l + r) / 2;
        return combine(query(2 * v, l, m, ql, qr), query(2 * v + 1, m + 1, r, ql, qr));
    }
};

int main() {
    FAST();
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    Segment_tree t(n, a);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int o;
        cin >> o;
        if (o == 1) {
            int k, x;
            cin >> k >> x;
            k--;
            t.update(1, 0, n - 1, k, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            auto [min, max, ret] = t.query(1, 0, n - 1, l, r);
            cout << ret << "\n";
        }
    }
}
