#include <bits/stdc++.h>
using namespace std;
using pp = pair<int, int>;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)


const int MAXN = 1e5+1;

int n, m;
// first: v, second: w
vector<pp> dsk[MAXN];
vector<int> dist;
int p[MAXN];

namespace sub1 {
    struct cmp {
        bool operator()(const pp &a, const pp &b) {
            return a.second > b.second;
        }
    };

    priority_queue<pp, vector<pp>, cmp> pq;

    void Dijkstra(int start) {
        dist.assign(n+1, INT_MAX);
        pq.push(make_pair(start, 0));
        dist[start] = 0;

        while (!pq.empty()) {
            pp i = pq.top();
            pq.pop();

            int u = i.first;
            int w = i.second;

            for (auto const &j : dsk[u]) {
                int v = j.first;
                int k = j.second;

                if (w > dist[v]) continue;
                if (dist[v] > dist[u] + k) {
                    dist[v] = dist[u] + k;
                    pq.push(make_pair(v, dist[v]));
                }
            }
        }
    }

    void run() {
        Dijkstra(1);
        if (dist[n] == INT_MAX) {
            cout << "impossible";
            exit(0);
        }

        cout << dist[n] << ' ' << 0;
    }
}

// namespace sub2 {
//     void run() {

//     }
// }

int theta = 3;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("quanho.inp", "r", stdin);
    freopen("quanho.out", "w", stdout);
    #endif
    
    cin >> n;

    bool ok1 = true, ok2 = true;

    FOR(i, 1, n) {
        cin >> p[i];

        if (p[i] != 0) {
            ok1 = false;
        }
    }

    if (ok1) theta = 1;

    cin >> m;
    FOR(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        dsk[u].push_back({v, w});
        dsk[v].push_back({u, w});

        if (w != 1 && !ok1 && n <= 1000) ok2 = false;
    }

    if (!ok2) theta = 2;

    switch (theta) {
        case 1:
            sub1::run();
            break;
    }

    return 0;
}