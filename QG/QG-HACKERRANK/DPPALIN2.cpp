#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxs = 1e4+1;
int dp[maxs][maxs];

string s;

int DP(int a, int b) {
    if (a > b || a > s.size()-1 || b < 0) return 0;
    if (a+1 == b) {
        if (s[a] == s[b]) {
            return dp[a][b] = 2;
        } else {
            return dp[a][b] = 1;
        }
    }
    if (a == b) return dp[a][b] = 1;
    if (dp[a][b]) return dp[a][b];

    if (s[a] == s[b]) {
        return dp[a][b] = DP(a+1, b-1)+2;
    } else {
        return dp[a][b] = max({DP(a+1, b), DP(a, b-1), DP(a+1, b-1)});
    }

    return dp[a][b];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> s;
    cout << DP(0, s.size()-1);
    return 0;
}