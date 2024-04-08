#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct re {
    int u, v, w;
    int idx;
};

struct cmp {
    bool operator()(const re &a, const re &b) {
        return a.w > b.w;
    }
};

const int MAXN = 5e5+1;
int parent[MAXN], sz[MAXN];
priority_queue<re, vector<re>, cmp> pq;
vector<re> cay_khung;
int n, m;

void make_set() {
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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("mst.inp", "r", stdin);
    freopen("mst.out", "w", stdout);
    #endif
    
    int _;
    cin >> _;

    cin >> n >> m;
    make_set();

    FOR(i, 1, m) {
        re tmp;
        cin >> tmp.u >> tmp.v >> tmp.w;
        tmp.idx = i;
        pq.push(tmp);
    }

    while (!pq.empty()) {
        if (cay_khung.size() == n-1) break;
        re top = pq.top();
        pq.pop();

        if (dsu_union(top.u, top.v)) {
            cay_khung.push_back(top);
        }
    }

    for (auto const &i : cay_khung) {
        cout << i.idx << ' ';
    }

    return 0;
}