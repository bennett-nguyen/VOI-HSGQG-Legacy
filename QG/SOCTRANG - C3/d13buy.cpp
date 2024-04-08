#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)
#define ii pair<int, int>

const int MAXN = 1e5+1;

int n, m;
vector<ii> dsk[MAXN];

namespace AC {
    struct cmp {
        bool operator()(const ii &a, const ii &b) {
            return a.second > b.second;
        }
    };

    priority_queue<ii, vector<ii>, cmp> pq;
    vector<int> d;

    void Dijkstra(int start) {
        d.assign(n+1, INT_MAX);
        pq.push(make_pair(start, 0));
        d[start] = 0;

        while (!pq.empty()) {
            ii i = pq.top(); pq.pop();

            int u = i.first;
            int w = i.second;

            if (w > d[u]) continue;
            for (auto const &j : dsk[u]) {
                int v = j.first;
                int k = j.second;

                if (d[v] > d[u] + k) {
                    d[v] = d[u] + k;
                    pq.push(make_pair(v, d[v]));
                }
            }
        }
    }

    void run() {
        Dijkstra(0);

        FOR(i, 1, n) {
            cout << d[i] << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n >> m;

    FOR(i, 1, n) {
        int tmp;
        cin >> tmp;
        dsk[0].push_back(make_pair(i, tmp));
        dsk[i].push_back(make_pair(0, tmp));
    }

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        dsk[u].push_back(make_pair(v, 2*w));
        dsk[v].push_back(make_pair(u, 2*w));
    }

    AC::run();
    return 0;
}