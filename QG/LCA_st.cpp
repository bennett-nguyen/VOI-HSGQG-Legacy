#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

int n, q;
int depth[MAXN], lookup[MAXN][17];
vector<int> dsk[MAXN];

void DFS(int current, int p) {
    depth[current] = depth[p]+1;
    lookup[current][0] = p;

    FOR(i, 1, 16) {
        lookup[current][i] = lookup[lookup[current][i-1]][i-1];
    }

    for (auto const &child : dsk[current]) {
        if (child == p) continue;
        DFS(child, current);
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    FOD(i, 16, 0) {
        if (depth[lookup[u][i]] >= depth[v]) {
            u = lookup[u][i];
        }
    }

    if (u == v) {
        return u;
    }

    FOD(i, 16, 0) {
        if (lookup[u][i] != lookup[v][i]) {
            u = lookup[u][i];
            v = lookup[v][i];
        }
    }

    return lookup[u][0];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> q;
    FOR(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
        dsk[v].push_back(u);
    }

    DFS(1, 0);

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << el;
    }
    
    return 0;
}