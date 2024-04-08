#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

struct Edge {
    int u, v, type;
    int idx;

    Edge(int _u, int _v, int _type, int _idx) {
        u = _u;
        v = _v;
        type = _type;
        idx = _idx;
    }
};

struct DSU {
    vector<int> lab;

    DSU(int n) { lab.assign(n+1, -1); }
    void reset(int n) { lab.clear(); lab.assign(n+1, -1); }
    int find(int u) { return lab[u] < 0 ? u : lab[u] = find(lab[u]); }
    bool same_set(int u, int v) { return find(u) == find(v); }
    bool join(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    }
};

int T;
int num_nodes, num_edges;
int a[maxn], b[maxn];
vector<Edge> edges;
DSU cay_a, cay_b;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> T;

    while (T--) {
        cin >> num_nodes >> num_edges;
        FOR(i, 1, num_nodes-1) cin >> a[i];
        FOR(i, 1, num_nodes-1) cin >> b[i];

        edges.clear();
        cay_a.reset(num_nodes);
        cay_b.reset(num_nodes);

        FOR(i, 1, num_edges) {
            int u, v, type;
            cin >> u >> v >> type;
            edges.push_back(Edge(u, v, type, i));
        }

        
    }

    return 0;
}