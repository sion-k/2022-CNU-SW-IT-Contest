#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// n / 2
const int N_MIN = 1, N_MAX = 10;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = 2 * rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    string s = rnd.next("[01]{%d}", n);
    cout << s << "\n";
}
