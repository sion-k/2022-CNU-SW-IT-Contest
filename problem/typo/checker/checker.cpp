#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int jury = ans.readInt();
    int participant = ouf.readInt(1, 2147483647, "ans");
    if (jury != participant) {
        quitf(_wa, "wa");
    }
    quitf(_ok, "ac");
}
