#include "testlib.h"
 
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(3, 2000, "n");
    inf.readEoln();
    bool sorted = true;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x = inf.readInt(0, n, "ai");
        if (x != 1) sorted = false;
        sum += x;
        if (i == n - 1) {
            inf.readEoln();
        } else {
            inf.readSpace();
        }
    }
    inf.readEof();
    ensuref(sum == n, "sum of a is not n");
    ensuref(!sorted, "already sorted");
}
