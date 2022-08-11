#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

inline int readAndCheckAnswer(InStream& in) {
    int ans = in.readInt(0, 100, "ans");
    return ans;
}
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int ja = readAndCheckAnswer(ans);
    int pa = readAndCheckAnswer(ouf);
    if (ja != pa) {
        quitf(_wa, "jury=%d, participant=%d", ja, pa);
    } else {
        quitf(_ok, "jury=%d, participant=%d", ja, pa);
    }
}
