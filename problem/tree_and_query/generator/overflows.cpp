#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = N_MAX;
    cout << n << "\n";
    
    for (int i = 1; i <= 49999; i++) {
        cout << 1 << " ";
    }
    
    for (int i = 50000; i <= 100000; i++) {
        cout << 0 << " \n"[i == 100000];
    }

    // left side
    for (int i = 1; i <= 49998; i++) {
        cout << i << " " << 49999 << "\n";
    }

    cout << 49999 << " " << 50000 << "\n";
    cout << 50000 << " " << 50001 << "\n";

    // right side
    for (int i = 50002; i <= 100000; i++) {
        cout << 50001 << " " << i << "\n";
    }

    int q = 3;
    cout << q << "\n";

    cout << 49999 << "\n";
    cout << 50000 << "\n";
    cout << 50001 << "\n";
}
