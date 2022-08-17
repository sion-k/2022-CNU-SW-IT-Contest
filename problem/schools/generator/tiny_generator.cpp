#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 10;
const int AB_MIN = 1, AB_MAX = 9;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    int ms = rnd.next(0, n);
    int m = rnd.next(0, ms);
    int s = ms - m;
    cout << n << " " << m << " " << s << "\n";
    for (int i = 0; i < n; i++) {
        int a = rnd.next(AB_MIN, AB_MAX);
        int b = rnd.next(AB_MIN, AB_MAX);
        cout << a << " " << b << "\n";
    }
}
