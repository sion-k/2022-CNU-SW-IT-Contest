#include <bits/stdc++.h>

using namespace std;

// 2^6 - 1개의 데이터를 순차적으로 출력
int main(int argc, char* argv[]) {
    int order = stoi(argv[1]);
    int n = 0;
    for (int i = 1; i <= order; i += (1 << n)) {
        n++;
    }
    cout << n << "\n";
    order -= ((1 << n) - 1);
    for (int i = n - 1; i >= 0; i--) {
        if (order & (1 << i)) {
            cout << "t";
        } else {
            cout << "s";
        }
    }
    cout << "\n";
}
