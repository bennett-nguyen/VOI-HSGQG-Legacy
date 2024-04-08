#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;
int n, m;
int parent[MAXN], sz[MAXN];
bool visited[MAXN];

struct re {
    int v, s;
};

struct re_ext {
    int u, v, s;
};

void make_set() {
    FOR(i, 1, n) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool dsu_union(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;

    return true;
}

vector<re_ext> v, cay_khung, canh_chua_duyet;
re trace[MAXN];

void kutko() {
    while (m--) {
        re_ext tmp;
        cin >> tmp.u >> tmp.v >> tmp.s;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), [](const re_ext &a, const re_ext &b) -> bool { return a.s > b.s; });
    for (auto const &canh : v) {
        if (cay_khung.size() != n-1) {
            if (dsu_union(canh.u, canh.v)) {
                cay_khung.push_back(canh);
            } else {
                canh_chua_duyet.push_back(canh);
            }
        } else {
            canh_chua_duyet.push_back(canh);
        }

    }
}

bool ok = false;
vector<re> dsk[MAXN];
vector<re_ext> truy_vet;
int min_val = INT_MAX, max_val = INT_MIN;

void DFS(int u, int start) {
    visited[u] = true;

    for (auto const &i : dsk[u]) {
        int v = i.v;
        int s = i.s;

        if (v != trace[u].v) {
            if (!visited[v]) {
                trace[v] = {u, s};
                DFS(v, start);
                if (ok) return;
            } else if (v == start) {
                ok = true;

                re_ext x = {u, v, s};
                while (x.u != trace[x].v) {
                    truy_vet.push_back({x, v, s});
                    
                }
                return;
            }
        }
    }
}

void sub1() {
    make_set();
    kutko();

    // chuyen dsc -> dsk
    for (auto const &i : cay_khung) {
        dsk[i.u].push_back({i.v, i.s});
        dsk[i.v].push_back({i.u, i.s});
    }

    for (auto const &i : canh_chua_duyet) {
        dsk[i.u].push_back({i.v, i.s});
        dsk[i.v].push_back({i.u, i.s});
        ok = false;
        DFS(i.u, i.u);
        dsk[i.u].pop_back();
        dsk[i.v].pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> m;
    


    return 0;
}