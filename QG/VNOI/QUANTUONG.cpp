#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for(int i = l; i <= r; i++)

struct re {
    int i, j;
    int d;
};

int n, m, p, q, s, t;
queue<re> Q;
bool blocked[201][201];
bool visited[201][n 201];

void reached_destination(int i, int j, re u) {
    if (i != s || j != t) return;
    cout << u.d+1;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> m >> p >> q >> s >> t;

    while (m--) {
        int x, y; cin >> x >> y;
        blocked[x][y] = true;
    }

    Q.push({p, q, 0});
    visited[p][q] = true;

    while (!Q.empty()) {
        re u = Q.front();
        int i = u.i, j = u.j;
        Q.pop();

        for (int k = 1; i+k <= n && j+k <= n; k++) {
            int i1 = i+k, j1 = j+k;
            if (blocked[i1][j1]) break;
            if (visited[i1][j1]) continue;

            Q.push({i1, j1, u.d+1});
            visited[i1][j1] = true;

            reached_destination(i1, j1, u);
        }

        for (int k = 1; i-k >= 1 && j-k >= 1; k++) {
            int i1 = i-k, j1 = j-k;
            if (blocked[i1][j1]) break;
            if (visited[i1][j1]) continue;

            Q.push({i1, j1, u.d+1});
            visited[i1][j1] = true;

            reached_destination(i1, j1, u);
        }

        for (int k = 1; i-k >= 1 && j+k <= n; k++) {
            int i1 = i-k, j1 = j+k;
            if (blocked[i1][j1]) break;
            if (visited[i1][j1]) continue;

            Q.push({i1, j1, u.d+1});
            visited[i1][j1] = true;

            reached_destination(i1, j1, u);
        }

        for (int k = 1; i+k <= n && j-k >= 1; k++) {
            int i1 = i+k, j1 = j-k;
            if (blocked[i1][j1]) break;
            if (visited[i1][j1]) continue;

            Q.push({i1, j1, u.d+1});
            visited[i1][j1] = true;

            reached_destination(i1, j1, u);
        }
    }

    cout << -1;
    return 0;
}
