#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int LEFT_MIN = 2, RANGE_MAX = 10;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int a = rnd.next(LEFT_MIN, RANGE_MAX);
    int b = rnd.next(a, RANGE_MAX);
    int c = rnd.next(LEFT_MIN, RANGE_MAX);
    int d = rnd.next(c, RANGE_MAX);

    cout << a << " " << b << "\n";
    cout << c << " " << d << "\n";
}
