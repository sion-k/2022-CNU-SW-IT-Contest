#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int order = stoi(argv[1]);

    cout << (order + 3) / 4 << " " << (order % 4 == 0 ? 4 : order % 4) << "\n";
}
