#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n, q;
const int MAXN = 1e5+1;
int depth[MAXN], parent[MAXN];
vector<int> dsk[MAXN];

void DFS(int current, int p, int d) {
    depth[current] = d;
    parent[current] = p;

    for (auto const &child : dsk[current]) {
        if (child == p) continue;
        DFS(child, current, d+1);
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    while (depth[u] != depth[v]) {
        u = parent[u];
    }

    while (u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u;
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

    DFS(1, 0, 1);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << el;
    }

    return 0;
}