#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int LEFT_MIN = 2, RANGE_MAX = 1'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int a = inf.readInt(LEFT_MIN, RANGE_MAX, "a");
    inf.readSpace();
    int b = inf.readInt(LEFT_MIN, RANGE_MAX, "b");
    inf.readEoln();
    int c = inf.readInt(LEFT_MIN, RANGE_MAX, "c");
    inf.readSpace();
    int d = inf.readInt(LEFT_MIN, RANGE_MAX, "d");
    inf.readEoln();
    inf.readEof();
}
