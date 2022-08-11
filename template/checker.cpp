#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

inline int readAndCheckAnswer(InStream& in) {
    int ans = in.readInt(INT_MIN, INT_MAX, "ans");
    in.quitf(_wa, "the answer is weird");
    return ans;
}
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int n = inf.readInt();

    int ja = readAndCheckAnswer(ans);
    int pa = readAndCheckAnswer(ouf);
    if (ja != pa) {
        quitf(_wa, "jury=%d, participant=%d", ja, pa);
    } else {
        quitf(_ok, "jury=%d, participant=%d", ja, pa);
    }
}
