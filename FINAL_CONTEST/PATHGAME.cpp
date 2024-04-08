#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int r, c, q;
char board[1001][1001];
int dp[1001][1001];

namespace sub1 {
    void driver() {

    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("PATHGAME.inp", "r", stdin);
    freopen("PATHGAME.out", "w", stdout);
    #endif

    cin >> r >> c >> q;
    FOR(i, 1, r) {
        FOR(j, 1, c) {
            cin >> board[i][j];
        }
    }

    if (max(r, c) <= 100 && q <= 3) {
        sub1::driver();
    }
    return 0;
}