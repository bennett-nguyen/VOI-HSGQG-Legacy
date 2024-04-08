    #include <bits/stdc++.h>
    using namespace std;

    #define el '\n'
    #define ll long long
    #define FOR(i, l, r) for (int i = l; i <= r; i++)
    #define FOD(i, l, r) for (int i = l; i >= r; i--)

    const int maxs = 1e3+1, maxt = 1e3+1;

    int dp[maxs][maxt];
    string s, t;

    int DP(int i, int j) {
        if (i == 0) return dp[0][j] = 0;
        if (j == 0) return dp[i][0] = 0;
        if (dp[i][j]) return dp[i][j];

        if (s[i] == t[j]) {
            dp[i][j] = DP(i-1, j-1)+1;
        } else {
            dp[i][j] = max(DP(i, j-1), DP(i-1, j)); 
        }

        return dp[i][j];
    }

    int main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        #ifndef ONLINE_JUDGE
        freopen("a.inp", "r", stdin);
        #endif

        cin >> s >> t;

        cout << DP(s.size()-1, t.size()-1)+1;
        return 0;
    }