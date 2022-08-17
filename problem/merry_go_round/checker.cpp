#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> a;
 
inline int readAndCheckAnswer(InStream& in) {
    int t = in.readInt(1, INT_MAX, "t");
    if (t == 0) {
        in.quitf(_wa, "at least 1 move needed");
    }
    return t;
}
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    n = inf.readInt();
    a = vector<int>(n);
    for (auto &x : a) {
        x = inf.readInt();
    }
    int ja = readAndCheckAnswer(ans);
    int pa = readAndCheckAnswer(ouf);
    if (ja != pa) {
        quitf(_wa, "jury=%d, participant=%d", ja, pa);
    } else {
        quitf(_ok, "jury=%d, participant=%d", ja, pa);
    }
}
