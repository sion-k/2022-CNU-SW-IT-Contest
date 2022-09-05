#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int LEFT_MIN = 2, LEFT_MAX = 10;
const int RIGHT_MIN = 990, RIGHT_MAX = 1'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int a = rnd.next(LEFT_MIN, LEFT_MAX);
    int b = rnd.next(a, LEFT_MAX);
    int c = rnd.next(RIGHT_MIN, RIGHT_MAX);
    int d = rnd.next(c, RIGHT_MAX);

    pair<int, int> yt(a, b);
    pair<int, int> yj(c, d);

    if (rnd.next(0, 1)) {
        swap(yt, yj);
    }

    cout << yt.first << " " << yt.second << "\n";
    cout << yj.first << " " << yj.second << "\n";
}
