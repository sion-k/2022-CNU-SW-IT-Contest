#include <bits/stdc++.h>

#define FAST() cin.tie(0)->sync_with_stdio(0)

using namespace std;

int n, m;
vector<string> a;

// 알파벳 별 위치
vector<pair<int, int>> slide('z' + 1);

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

bool inRange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }

bool isAlpha(char x) {
    return 'A' <= x && x <= 'Z' || 'a' <= x && x <= 'z';
}

bool isLower(char x) {
    return 'a' <= x && x <= 'z';
}

char swapcase(char x) {
    if (isLower(x)) {
        return x - 32;
    } else {
        return x + 32;
    }
}

int bfs() {
    queue<tuple<int, int, int>> q;
    vector<vector<vector<int>>> dist(2, vector<vector<int>>(n, vector<int>(m, -1)));
    q.emplace(0, 0, 0);
    dist[0][0][0] = 0;
    while (!q.empty()) {
        auto [t, y, x] = q.front();
        q.pop();
        // 1. 미끄럼틀을 이용하는 경우
        if (isAlpha(a[y][x])) {
            int nt = t ^ 1;
            // 짝수번 이용했다면 소문자여야 하고
            // 홀수번 이용했다면 대문자여야 한다.
            if (t ^ isLower(a[y][x])) {
                auto [ny, nx] = slide[swapcase(a[y][x])];
                if (dist[nt][ny][nx] == -1) {
                    q.emplace(nt, ny, nx);
                    dist[nt][ny][nx] = dist[t][y][x] + 1;
                }
            }
        }
        // 2. 인접한 칸으로 이동하는 경우
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d], nx = x + dx[d];
            if (inRange(ny, nx) && a[ny][nx] != '#' && dist[t][ny][nx] == -1) {
                q.emplace(t, ny, nx);
                dist[t][ny][nx] = dist[t][y][x] + 1;
            }
        }
    }
    return min(dist[0][n - 1][m - 1], dist[1][n - 1][m - 1]);
}

int main() {
    FAST();
    cin >> n >> m;
    a = vector<string>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (isAlpha(a[y][x])) {
                slide[a[y][x]] = { y, x };
            }
        }
    }
    cout << bfs() << "\n";
}
