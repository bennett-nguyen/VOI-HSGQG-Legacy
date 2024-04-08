#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define forw(i, l, r) for (int i = l; i <= r; i++)
#define fodd(i, l, r) for (int i = l; i >= r; i--)

const int maxr = 1e4+1, maxc = 1e4+1;

int r, c;
int dp[maxr][maxc];

int DP(int _r, int _c) {
    if (_r == _c) return dp[_r][_c] = 0;
    if (dp[_r][_c]) return dp[_r][_c];

    dp[_r][_c] = 1e9;
    forw(a, 1, _r-1) {
        dp[_r][_c] = min({dp[_r][_c], DP(a, _c)+DP(_r-a, _c)+1});
    }

    forw(b, 1, _c-1) {
        dp[_r][_c] = min({dp[_r][_c], DP(_r, b)+DP(_r, _c-b)+1});
    }

    return dp[_r][_c];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("a.inp", "r", stdin);
    // #endif

    cin >> r >> c;
    cout << DP(r, c);
    return 0;
}