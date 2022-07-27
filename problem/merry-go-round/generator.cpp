#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(3, 2000);
    cout << n << "\n";
    vector<int> a(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
        a[i] = i;
    }
    shuffle(a.begin(), a.end());
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    vector<int> c(n);
    for (int i = 0; i < n - 1; i++) {
        c[i] = b[i] / 2 + 1;
    }
    c[n - 1] = n;
    for (int i = n - 1; i >= 1; i--) {
        c[i] -= c[i - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << c[i] << " \n"[i == n - 1];
    }
}
