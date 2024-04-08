#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxrc = 301;

int r, c, k;
int board[maxrc][maxrc];
pair<int, int> parent[maxrc][maxrc];
ll dp[maxrc][maxrc];
ll dp2[maxrc][maxrc];

namespace sub1 {
    void driver() {
        while (k--) {
            int u, v, p, q;
            cin >> u >> v >> p >> q;
            parent[u][v] = make_pair(0, 0);
            pair<int, int> blocked = make_pair(0, 0);
            ll max_val = INT_MIN;

            memset(dp, 0, maxrc*maxrc*sizeof(dp[0][0]));
            memset(dp2, 0, maxrc*maxrc*sizeof(dp2[0][0]));

            FOR(i, u, p) {
                FOR(j, v, q) {
                    if (i == 1) {
                        dp[i][j] = dp[i][j-1] + board[i][j];
                        parent[i][j] = make_pair(i, j-1);
                    } else if (j == 1) {
                        dp[i][j] = dp[i-1][j] + board[i][j];
                        parent[i][j] = make_pair(i-1, j);
                    } else {q
                        if (dp[i][j-1] > dp[i-1][j]) {
                            parent[i][j] = make_pair(i, j-1);
                            dp[i][j] = dp[i][j-1] + board[i][j];
                        } else if (dp[i][j-1] < dp[i-1][j]) {
                            dp[i][j] = dp[i-1][j] + board[i][j];
                            parent[i][j] = make_pair(i-1, j);
                        }
                    }
                }
            }

            pair<int, int> x = parent[p][q];

            while (x.first != u && x.second != v) {
                if (max_val < board[x.first][x.second]) {
                    max_val = board[x.first][x.second];
                    blocked = x;
                }

                x = parent[x.first][x.second];
            }

            FOR(i, u, p) {
                FOR(j, v, q) {
                    if (i == blocked.first && j == blocked.second) {
                        dp2[i][j] = INT_MIN;
                        continue;
                    } if (i == 1) {
                        dp2[i][j] = dp2[i][j-1] + board[i][j];
                    } else if (j == 1) {
                        dp2[i][j] = dp2[i-1][j] + board[i][j];
                    } else {
                        dp2[i][j] = max(dp2[i][j-1], dp2[i-1][j]) + board[i][j];
                    }
                }
            }

            cout << dp2[p][q] << el;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);
    // freopen("TABLE.inp", "r", stdin);
    // freopen("TABLE.out", "w", stdout);

    cin >> r >> c >> k;

    FOR(i, 1, r) {
        FOR(j, 1, c) {
            cin >> board[i][j];
        }
    }

    sub1::driver();
    return 0;
}