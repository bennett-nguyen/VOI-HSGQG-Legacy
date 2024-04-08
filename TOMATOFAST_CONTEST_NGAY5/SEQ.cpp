#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 801;

int n, k;
ll psum[maxn];
ll max_ans = INT_MIN;
ll dp[maxn][maxn][maxn];

ll dfs(int l, int r, int depth) {
    if (dp[l][r][depth]) return dp[l][r][depth];

    if (depth < k) {
        if (l == r) return dp[l][r][depth] = -1;

        FOR(mid, l, r) {
            ll val = (psum[mid]-psum[l-1])*(psum[r]-psum[mid]);
            
            ll left = dfs(l, mid, depth+1);
            ll right = dfs(mid+1, r, depth+1);

            ll c = max(left, right);
            dp[l][r][depth] = max(dp[l][r][depth], c+val);
        }
    }

    return dp[l][r][depth];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> k;
    FOR(i, 1, n) {
        ll tmp;
        cin >> tmp;
        psum[i] = psum[i-1]+tmp;
    }

    cout << dfs(1, n, 0);
    return 0;
}
