#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();

    string s = inf.readToken("[st]+", "s");
    inf.readEoln();

    ensuref(s.size() == n, "size of s is not %d", n);

    map<int, int> cnt;
    int p = -1;
    for (int i = n - 1; i >= 0; i--) {
        cnt[s[i]]++;
        if (cnt['s'] == cnt['t']) {
            p = i;
        }
    }
    ensuref(p != -1, "The answer should not empty string");
    
    inf.readEof();
}
