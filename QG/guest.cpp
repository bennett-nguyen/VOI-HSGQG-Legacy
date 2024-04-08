#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

// My solution to the Min Cost Path

const int MAX = 1e3+1;

int cost[MAX][MAX];
int dp[MAX][MAX];

int rows, columns, m, n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    // Reading inputs
    cin >> rows >> columns >> m >> n;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> cost[i][j];
        }
    }

    dp[0][0] = cost[0][0];

    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }

    for (int i = 1; i < columns; i++) {
        dp[0][i] = dp[0][i-1] + cost[0][i];
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + cost[i][j];
        }
    }

    cout << dp[m][n];
    
    return 0;
}