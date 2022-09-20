#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 97, N_MAX = 100;

string mbti_ptrn = "[IE][NS][FT][PJ]";

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    string s = rnd.next(mbti_ptrn);
    cout << s << "\n";

    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        string ti = s;
        cout << ti << "\n";
    }
}
