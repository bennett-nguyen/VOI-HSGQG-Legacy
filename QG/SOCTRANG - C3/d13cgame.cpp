#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

/*
Voi moi mot nut u, ta biet duoc:

h[u]: thoi gian di tu goc -> u
g[u]: thoi gian nho nhat de 1 nguoi o nut la chay toi u

h[u] < g[u] -> can't decide
=> f(u) = tong f(v) for v = con

else: f(u) = 1
*/


const int MAXN = 1e6+1;

int n;
vector<int> dsk[MAXN];
int h[MAXN], g[MAXN], f[MAXN];

void DFS(int u, int parent) {
    g[u] = INT_MAX;

    for (auto const &v : dsk[u]) {
        if (v == parent) continue;
        h[v] = h[u]+1;
        DFS(v, u);
        g[u] = min(g[u], g[v]+1);
    }

    if (g[u] == INT_MAX) g[u] = 0;
}

void DFS_SUM(int u, int parent) {
    if (h[u] >= g[u]) {
        f[u] = 1;
    } else {
        for (auto const &v : dsk[u]) {
            if (v == parent) return;
            DFS_SUM(v, u);
            f[u] += f[v];
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n; 

    FOR(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
        dsk[v].push_back(u);
    }

    DFS(1, 0);
    DFS_SUM(1, 0);

    cout << f[1];
    return 0;
}