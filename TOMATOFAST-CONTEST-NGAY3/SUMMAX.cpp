#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 2e5+1;

int n;
int a[maxn], dp[maxn];
vector<int> dsk[maxn];

void dfs(int u, int parent) {
    dp[u] = a[u];
    for (auto const &v : dsk[u]) {
        if (v != parent) {
            dfs(v, u);
            dp[u] = max(dp[u], dp[v] + a[u]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) {
        int tmp;
        cin >> tmp;

        if (!tmp) continue;

        dsk[i].push_back(tmp);
        dsk[tmp].push_back(i);
    }

    dfs(1, 0);
    cout << dp[1];
    return 0;
}