#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 96, N_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    
    // 오른쪽에 끝에 s를 m개, t를 m개 총 2m길이만큼 붙인다.
    int m = 1;
    string s;

    char c = rnd.next(0, 1) ? 's' : 't';
    // 앞에 n - 2m개는 랜덤하게 붙임
    for (int i = 0; i < n - 2 * m; i++) {
        s.push_back(c);
    }

    // 오른쪽에 끝에 s를 m개, t를 m개 총 2m길이만큼 붙인다.
    for (int i = 0; i < m; i++) {
        s.push_back('s');
        s.push_back('t');
    }

    // 뒤에 2m개만 섞어준다.
    shuffle(s.begin() + n - 2 * m, s.end());
    
    cout << s << "\n";
}
