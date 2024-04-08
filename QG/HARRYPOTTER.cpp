#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

int n, t;
int a[maxn];
bool dp[maxn][maxn];
int max_ans = INT_MIN;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> t;
    FOR(i, 1, n) {
        cin >> a[i];
        dp[i][i] = true;
    }

    FOR(i, 2, n) {
        if (abs(a[i]-a[i-1]) <= t) {
            dp[i-1][i] = true;
        }
    }

    FOR(j, 3, n) {
        FOR(i, 1, j-1) {
            if (i+1 > j-1) continue;

            if (abs(a[i]-a[j]) <= t) {
                dp[i][j] = dp[i+1][j-1] && dp[i+1][j] && dp[i][j-1];

                if (i == 4 && j == 7) {
                    cout << dp[i+1][j-1] << ' ' << dp[i+1][j] << ' ' << dp[i][j-1];
                }

                if (dp[i][j]) {
                    max_ans = max(max_ans, j-i+1);
                }
            } else {
                dp[i][j] = false;
            }
        }
    }
    
    // FOR(i, 1, n) {
    //     FOR(j, i, n) {
    //         cout << dp[i][j] << ' ' << i << ' ' << j << el;
    //     }
    // }

    // cout << max_ans;
    return 0;
}