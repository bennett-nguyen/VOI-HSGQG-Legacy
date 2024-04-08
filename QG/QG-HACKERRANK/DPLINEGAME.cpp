#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e6+1;

int n;
int arr[maxn];
int dp[maxn][2];

// 0: -
// 1: +

ll max_res = LLONG_MIN;



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    FOR(i, 1, n) cin >> arr[i];

    dp[1][0] = dp[1][1] = arr[1];

    FOR(i, 2, n) {
        FOR(j, 1, i-1) {
            dp[i][1] = arr[i];

            dp[i][0] = max(dp[i][0], dp[j][1]-arr[i]);
            if (j == 1) continue;
            dp[i][1] = max(dp[i][1], dp[j][0]+arr[i]);
        }
    }

    FOR(i, 1, n) {
        FOR()
    }


    return 0;
}