#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 5e5+1;

struct Edge {
    int u, v, w, idx;
    bool in_tree = false;
};

int theta;
int num_nodes, num_edges;
int parent[MAXN], sz[MAXN];
Edge E[MAXN];

void make_set() {
    FOR(i, 1, num_nodes) { 
        parent[i] = i;
        sz[i] = 1;
    }
}

int find_set(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_set(parent[u]);
}

bool dsu_union(int u, int v) {
    u = find_set(u);
    v = find_set(v);

    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    return true;
}

bool same_set(int u, int v) {
    return find_set(u) == find_set(v);
}

namespace AC {
    void driver() {

    }
}

namespace sub5 {
    void driver() {
        make_set();

        sort(E+1, E+1+num_edges, [](const Edge &a, const Edge &b) -> bool { return a.w < b.w; });

        FOR(i, 1, num_edges) {
            Edge e = E[i];

            if (dsu_union(e.u, e.v)) {
                e.in_tree = true;
            }
        }

        sort(E+1, E+1+num_edges, [](const Edge &a, const Edge &b) -> bool { return a.idx < b.idx; });
        FOR(i, 1, num_edges) {
            Edge e = E[i];

            if (e.in_tree) {
                cout << "Yes ";
            } else {
                cout << "No ";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("mst.inp", "r", stdin);
    freopen("mst.out", "w", stdout);
    #endif
    
    cin >> theta >> num_nodes >> num_edges;

    FOR(i, 1, num_edges) {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }

    if (theta == 1) {
        sub1::driver();
    } else if (theta == 5) {
        sub5::driver();
    }

    return 0;
}