#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = N_MAX;
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        int s = rnd.next(0, 1);
        if (s) {
            cout << "s";
        } else {
            cout << "t";
        }
    }
    cout << "\n";
}
