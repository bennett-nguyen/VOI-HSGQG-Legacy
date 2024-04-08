#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 50001;

int n, k;
long long ans;
vector<int> dsk[maxn];
int dp[maxn][201];

void dfs(int u, int parent) {
    dp[u][0] = 1;
    for (auto const &v : dsk[u]) {
        if (v == parent) continue;
        dfs(v, u);

        FOR(i, 0, k-1) {
            ans += dp[u][i] * dp[v][k-i-1];
        }

        FOR(i, 0 , k-1) {
            dp[u][i+1] += dp[v][i];
        }
    }

}

int root;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> k;
    FOR(i, 1, n) {
        int tmp;
        cin >> tmp;
        if (!tmp) { root = i; continue; }
        dsk[tmp].push_back(i);
        dsk[i].push_back(tmp);
    }

    dfs(root, 0);
    cout << ans;
    
    return 0;
}