#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct Edge {
    int u, v, w;
    bool is_modified = false;
    int modified_value = 0;

    void reset() {
        is_modified = false;
        modified_value = 0;
    }
};

const int maxn = 1e5+1;
const int maxm = 1e6+1;

int T, n, m, q;
vector<Edge> edges;

struct DSU {
    vector<int> lab;

    DSU(int n=0) { lab.assign(n+1, -1); }
    void reset(int n = 0) { lab.clear(); lab.assign(n+1, -1); }
    int find(int u) { return lab[u] < 0 ? u : lab[u] = find(lab[u]); }
    bool same_set(int u, int v) { return find(u) == find(v); }

    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;

        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    } 
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> T;

    while (T--) {
        edges.clear();
        cin >> n >> m >> q;

        FOR(i, 1, m) {
            Edge tmp;
            cin >> tmp.u >> tmp.v >> tmp.w;
            edges.push_back(tmp);
        }

        while (q--) {
            int idx_query, s, t, c;
            cin >> idx_query >> s;

            DSU dsu(n);
            for (Edge &e : edges) e.reset();

            while (s--) {
                cin >> t >> c;
                edges[t-1].modified_value = c;
                edges[t-1].is_modified = true;
            }

            int mark = edges[idx_query-1].is_modified ? edges[idx_query-1].modified_value : edges[idx_query-1].w;

            for (Edge const &e : edges) {
                int e_val = e.is_modified ? e.modified_value : e.w;

                if (e_val < mark) {
                    dsu.join(e.u, e.v);
                }
            }

            if (!dsu.same_set(edges[idx_query-1].u, edges[idx_query-1].v)) {
                cout << "NO" << el;
            } else {
                cout << "YES" << el;
            }
        }
    }

    return 0;
}