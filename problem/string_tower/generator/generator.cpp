#include <bits/stdc++.h>
#include "testlib.h"

#define SIZE(x) ((int)(x).size())

using namespace std;

// 가능한 경우 데이터
const int N_MIN = 1, N_MAX = 100;
const int M_MIN = 1, M_MAX = 100;

// 길이 1이상의 접두사 반환
string prefix(int n, string s) {
    int length = rnd.next(1, n);
    return s.substr(0, length);
}

// 길이 1이상의 접미사 반환
string suffix(int n, string s) {
    int length = rnd.next(1, n);
    return s.substr(n - length);
}

// pre가 접두사가 되도록
// m길이의 문자열을 만들어서 반환
string make_string_prefix(int m, string pre) {
    string ptrn = "[a-z]{" + to_string(m - SIZE(pre)) + "}";
    string suf = rnd.next(ptrn);

    pre.append(suf);
    return pre;
}

// suf가 접미사가 되도록
// m길이의 문자열을 만들어서 반환
string make_string_suffix(int m, string suf) {
    string ptrn = "[a-z]{" + to_string(m - SIZE(suf)) + "}";
    string pre = rnd.next(ptrn);

    pre.append(suf);
    return pre;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(N_MIN, N_MAX);
    int m = rnd.next(M_MIN, M_MAX);
    cout << n << " " << m << "\n";

    string prev = make_string_prefix(m, "");
    cout << prev << "\n";

    for (int i = 1; i < n; i++) {
        if (rnd.next(0, 1)) {
            string pre = prefix(SIZE(prev), prev);
            string si = make_string_suffix(m, pre);
            
            cout << si << "\n";
            prev = si;
        } else {
            string suf = suffix(SIZE(prev), prev);
            string si = make_string_prefix(m, suf);

            cout << si << "\n";
            prev = si;
        }
    }
}
