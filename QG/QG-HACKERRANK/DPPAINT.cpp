#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

int n;
int a[maxn], b[maxn], c[maxn];
int dp[maxn][3];


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n;

    FOR(i, 1, n) cin >> a[i] >> b[i] >> c[i];

    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];

    FOR(i, 2, n) {
        dp[i][0] = dp[i][1] = dp[i][2] = 1e9;
        FOR(k, 0, 2) {
            FOR(j, 0, 2) {
                if (j == k) continue;
                
                int val;

                if (k == 0) {
                    val = a[i];
                } else if (k == 1) {
                    val = b[i];
                } else if (k == 2) {
                    val = c[i];
                }

                dp[i][k] = min(dp[i][k], dp[i-1][j]+val);
            }
        }
    }
    
    cout << min({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}