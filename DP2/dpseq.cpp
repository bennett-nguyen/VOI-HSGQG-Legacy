#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 10001;

int n, k;
int arr[maxn], dp[maxn];

int DP(int i) {
    if (dp[i]) return dp[i];

        
    return dp[i];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> k;
    FOR(i, 1, n) cin >> arr[i];

    DP(n);
    cout << *max_element(dp+1, dp+1+n);
    return 0;
}