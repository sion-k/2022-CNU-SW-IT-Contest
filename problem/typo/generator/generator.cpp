#include "testlib.h"
#include <iostream>
 
using namespace std;
 
void flip(string &s, int i) {
    s[i] = s[i] == '(' ? ')' : '(';
}
 
string balanced_bracket_sequence_v1(int n) {
    auto res = string(n, '(') + string(n + 1, ')');
    shuffle(res.begin(), res.end());
    vector<int> pref(2 * n + 2, 0);
    for (int x = 0; x < 2 * n + 1; x++)
        pref[x + 1] = pref[x] + (res[x] == '(' ? 1 : -1);
    int idx =
        int(min_element(pref.begin(), pref.end()) - pref.begin());
    rotate(res.begin(), res.begin() + idx, res.end());
    return res.substr(0, 2 * n);
}
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 10);
    string s = balanced_bracket_sequence_v1(n);
    int k = rnd.next(0, n);
    if (0 <= k && k < n) {
        flip(s, k);
    }
    cout << s << "\n";
}
