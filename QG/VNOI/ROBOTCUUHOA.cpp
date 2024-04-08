#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct re {
    int v, t, c;
};

struct re_bfs {
    int v, t;
};

struct cmp {
    bool operator()(const re_bfs &a, const re_bfs &b) {
        return a.t > b.t;
    }
};

const int MAXN = 501;

int n, m;
vector<re> dsk[MAXN];
bool fuel_station[MAXN];
int d1[MAXN], dn[MAXN];
priority_queue<re_bfs, vector<re_bfs>, cmp> pq;

void dijkstra(int start, int d[]) {
    fill_n(d, MAXN, INT_MAX);
    d[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        re_bfs u = pq.top();
        pq.pop();

        if (u.t > d[u.v]) continue;
        for (auto const &v : dsk[u.v]) {
            if (d[v.v] > d[u.v] + v.t) {
                d[v.v] = d[u.v] + v.t;
                pq.push({v.v, d[v.v]});
            }
        }
    }
}

bool bfs(int x) {
    queue<pair<int, int>> q;
    q.push({1, x});

    while (!q.empty()) {
        int u = q.front().first;
        int w = q.front().second;

        q.pop();

        for (auto const &v : dsk[u]) {
            if (d1[u] + v.t + dn[v.v] == d1[n] && w >= v.c) {
                if (v.v == n) return true;
                if (fuel_station[v.v]) {
                    q.push({v.v, x});
                } else {
                    q.push({v.v, w-v.c});
                }
            }
        }
    }

    return false;
}

int bin_search() {
    int l = 0, r = 1e9, ans = 0;

    while (l <= r) {
        int mid = (l+r)/2;
        if (bfs(mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid+1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    FOR(i, 1, n) cin >> fuel_station[i];

    cin >> m;

    FOR(i, 1, m) {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        dsk[u].push_back({v, t, c});
        dsk[v].push_back({u, t, c});
    }

    dijkstra(1, d1);
    dijkstra(n, dn);
    cout << bin_search();

    return 0;
}