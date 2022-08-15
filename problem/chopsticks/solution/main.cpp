#include <bits/stdc++.h>

using namespace std;

// t번째 턴이고, 공격할 사람이 손가락을 편 개수가 a일 때
// 누가 이기는지 반환
int game(int a, int b, int t) {
    if (t >= 4) return -1;
    if (a == 0) return t % 2;
    b = (b + a) % 5;
    swap(a, b);
    return game(a, b, t + 1);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << game(a, b, 0) << "\n";
}
