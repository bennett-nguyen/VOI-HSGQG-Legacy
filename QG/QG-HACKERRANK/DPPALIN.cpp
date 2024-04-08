#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxs = 256;

int q;
string s;
bool dp[maxs][maxs];

bool DP(int a, int b) {
    if (a == b) return dp[a][b] = true;
    if (a+1 == b) {
        return dp[a][b] = (s[a] == s[b]);
    }

    if (s[a] == s[b]) {
        dp[a][b] = DP(a+1, b-1);
    }

    return dp[a][b];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> s >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (DP(a-1, b-1)) {
            cout << "YES" << el;
        } else {
            cout << "NO" << el;
        }
    }
    return 0;
}