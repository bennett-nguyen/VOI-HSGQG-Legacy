#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)
using pii = pair<int, int>;

struct cmp {
    bool operator()(const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

const int maxn = 10001;

vector<pii> dsk[maxn];
int d[maxn];
int num_edges, num_nodes;
priority_queue<pii, vector<pii>, cmp> pq;

void Dijkstra(int start) {
    memset(d, 0x3f, sizeof(d));
    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        int u = pq.top().first;
        int kc = pq.top().second;
        pq.pop();

        if (kc > d[u]) continue;
        for (auto const &j : dsk[u]) {
            int v = j.first;
            int w = j.second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(make_pair(v, d[v]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("a.inp", "r", stdin);
    freopen("b.out", "w", stdout);
    #endif

    cin >> num_nodes >> num_edges;
    FOR(i, 1, num_edges) {
        int u, v, w;
        cin >> u >> v >> w;
        dsk[u].push_back(make_pair(v, w));
        dsk[v].push_back(make_pair(u, w));
    }

    Dijkstra(1);
    cout << d[num_nodes];

    return 0;
}