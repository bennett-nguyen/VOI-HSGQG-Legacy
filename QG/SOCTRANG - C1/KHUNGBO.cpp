#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)
#define ii pair<int, int>

const int MAXN = 1e5+1, MAXM = 1e4+1;

struct Edge {
    int u = 0, v = 0;
    int cost = 0;
    bool in_tree = false;

    Edge() {}
    Edge(int _u, int _v, int _cost) {
        u = _u;
        v = _v;
        cost = _cost;
    }
};

int T;
int num_nodes, num_edges, num_queries;
vector<int> dsk[MAXN];
Edge edges[MAXM];

namespace Kruskal {
    int parent[MAXN], sz[MAXN];

    void make_set(int n) {
        FOR(i, 1, n) {
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

    void driver() {
        make_set(num_nodes);

        FOR(i, 1, num_edges) {
            edges[i].in_tree = dsu_union(edges[i].u, edges[i].v);
        }
    }
}

namespace LCA {
    #define LOG 17
    int depth[MAXN];
    int lookup[MAXN][LOG+1];
    ll dist_from_root[MAXN];

    void DFS(int u) {
        for (auto const &i : dsk[u]) {
            if (edges[i].in_tree) {
                int v = edges[i].u ? edges[i].v : edges[i].u;
                if (v == lookup[u][0]) continue;

                lookup[v][0] = u;
                depth[v] = depth[u]+1;
                dist_from_root[v] = dist_from_root[u] + edges[i].cost;
                DFS(v);
            }
        }
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        FOD(i, 16, 0) {
            if (depth[lookup[u][i]] >= depth[v]) {
                u = lookup[u][i];
            }
        }

        if (u == v) return u;

        FOD(i, 16, 0) {
            if (lookup[u][i] != lookup[v][i]) {
                u = lookup[u][i];
                v = lookup[v][i];
            }
        }

        return lookup[u][0];
    }

    ll dist_tree(int u, int v) {
        return dist_from_root[u] + dist_from_root[v] - 2 * dist_from_root[LCA(u, v)];
    }
}

namespace Dijkstra {
    struct cmp {
        bool operator()(const ii &a, const ii &b) {
            return a.second > b.second;
        }
    };

    vector<ii> dsk[MAXN];
    vector<ll> dist[MAXN];
    vector<int> nodes;
    priority_queue<ii, vector<ii>, cmp> pq;

    void Dijkstra(int start) {
        pq = priority_queue<ii, vector<ii>, cmp>();
        dist[start].assign(num_nodes+1, INT_MAX);

        dist[start][start] = 0;
        pq.push(make_pair(start, 0));

        while (!pq.empty()) {
            ii i = pq.top(); pq.pop();
            int u = i.first;
            int w = i.second;

            if (w > dist[start][u]) continue;
            for (auto const &j : Dijkstra::dsk[u]) {
                int v = j.first;
                int k = j.second;

                if (dist[start][v] > dist[start][u] + k) {
                    dist[start][v] = dist[start][u] + k;
                    pq.push(make_pair(v, dist[start][v]));
                }
            }
            
        }
    }

    void driver() {
        nodes.clear();

        FOR(i, 1, num_edges) {
            if (!edges[i].in_tree) {
                nodes.push_back(edges[i].u);
            }
        }

        sort(nodes.begin(), nodes.end());
        nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());

        for (auto const &s : nodes) {
            Dijkstra(s);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> T;
    
    while (T--) {
        cin >> num_nodes >> num_edges >> num_queries;
        FOR(i, 1, num_edges) {
            int u, v, d;
            cin >> u >> v >> d;

            edges[i] = Edge(u, v, d);
            dsk[u].push_back(i);
            dsk[v].push_back(i);
            Dijkstra::dsk[u].push_back(make_pair(v, d));
            Dijkstra::dsk[v].push_back(make_pair(u, d));
        }

        Kruskal::driver();
        Dijkstra::driver();

        while (num_queries--) {
            int u, v;
            cin >> u >> v;

            ll res = LCA::dist_tree(u, v);

            for (auto const &i : Dijkstra::nodes) {
                res = min(res, Dijkstra::dist[i][u] + Dijkstra::dist[i][v]);
            }

            cout << res << el;
        }
    }

    return 0;
}