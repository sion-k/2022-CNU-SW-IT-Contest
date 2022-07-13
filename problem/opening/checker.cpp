#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int n, m, k;
 
inline int readAndCheckAnswer(InStream& in) {
    int t = in.readInt(1, INT_MAX, "t");
    if (t % k) {
        in.quitf(_wa, "t must be divisible by k");
    }
    if (!(n <= m * (t / k))) {
        in.quitf(_wa, "some guests are left");
    }
    return t;
}
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    n = inf.readInt();
    m = inf.readInt();
    k = inf.readInt();
 
    int ja = readAndCheckAnswer(ans);
    int pa = readAndCheckAnswer(ouf);
    if (ja != pa) {
        quitf(_wa, "jury=%d, participant=%d", ja, pa);
    } else {
        quitf(_ok, "jury=%d, participant=%d", ja, pa);
    }
}
