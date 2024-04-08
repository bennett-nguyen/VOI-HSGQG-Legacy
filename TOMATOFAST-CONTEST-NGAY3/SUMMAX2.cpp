#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 2e5+1;

int n;
ll a[maxn], dp1[maxn], dp0[maxn];
vector<ll> dsk[maxn];

void dfs(ll u, ll parent) {
    dp1[u] = a[u];

    for (auto const &v : dsk[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp1[u] += dp0[v];
        dp0[u] += max(dp1[v], dp0[v]);
    }
}

ll root;

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

        if (!tmp) {
            root = i;
            continue;
        }

        dsk[i].push_back(tmp);
        dsk[tmp].push_back(i);
    }

    dfs(root, 0);
    cout << max(dp0[root], dp1[root]);
    
    return 0;
}