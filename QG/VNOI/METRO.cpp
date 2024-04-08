#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

struct re {
    int v, w, idx;
    re() {}
    re(int _v, int _w, int _idx) {
        v = _v;
        w = _w;
        idx = _idx;
    }
};

re make_re(int _v, int _w, int _idx) {
    return re(_v, _w, _idx);
}

struct cmp {
    bool operator()(const re &a, const re &b) {
        return a.w > b.w;
    }
};

int num_nodes, num_edges, u, v, delta;
int d[maxn];
vector<re> dsk[maxn];
priority_queue<re, vector<re>, cmp> pq;

void Dijkstra() {

}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    memset(d, 0x3f, sizeof(d));
    cin >> num_nodes >> num_edges >> u >> v >> delta;
    d[u] = 0;

    FOR(i, 1, num_edges) {
        int u, v, w;
        cin >> u >> v >> w;
        dsk[u].push_back(re(v, w, i));
        dsk[v].push_back(re(u, w, i));
    }

    for (auto const &i : dsk[u]) {
        d[i.v] = i.w;
        pq.push(make_re(i.v, i.w, i.idx));
    }
    
    return 0;
}