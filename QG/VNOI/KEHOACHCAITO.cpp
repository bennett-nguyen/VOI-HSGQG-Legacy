#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 2e5+1;

ll v, e, stp = 0;
vector<ll> dsk[maxn];
unordered_map<ll, bool> fre;
unordered_map<ll, ll> cnt;

void BFS(int start) {
    queue<ll> q;
    q.push(start);
    fre[start] = true;
    cnt[stp]++;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto const &v : dsk[u]) {
            if (fre[v]) continue;
            cnt[stp]++;
            q.push(v);
            fre[v] = true;
        }
    }
}

namespace Tarjan {
    ll TIME = 0;
    ll cha[maxn], color[maxn], low[maxn], num[maxn];
    ll con[maxn];

    #define WHITE 0
    #define GRAY 1
    #define BLACK 2

    vector<ll> cau;

    void DFS(ll u) {
        TIME++;
        low[u] = num[u] = TIME;
        color[u] = GRAY;
        con[u] = 1;
        
        for (auto const &v : dsk[u]) {
            if (v == cha[u]) continue;

            if (color[v] == GRAY) {
                low[u] = min(low[u], num[v]);
            } else if (color[v] == WHITE) {
                cha[v] = u;
                DFS(v);
                con[u] += con[v];
                low[u] = min(low[u], low[v]);
            }
        }

        if (cha[u] != -1 && low[u] >= num[u]) cau.push_back(u);
        color[u] = BLACK;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> v >> e;

    FOR(i, 1, e) {
        ll u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
        dsk[v].push_back(u);
    }

    FOR(i, 1, v) {
        if (fre[i]) continue;
        stp++;

        if (stp > 2) {
            cout << 0;
            return 0;
        }

        BFS(i);
    }

    using namespace Tarjan;

    FOR(i, 1, v) {
        if (color[i] == WHITE) {
            cha[i] = -1;
            DFS(i);
        }
    }

    if (stp == 2) {
        ll c1 = cnt[1];
        ll c2 = cnt[2];

        cout << (e - cau.size()) * c1 * c2;
    } else if (stp == 1) {
        ll res = (e - cau.size()) * (v * (v - 1) / 2 - e);

        for (auto const &i : cau) {
            // cout << con[i] << ' ' << con[cha[i]] << el;
            res += con[i] * (v - con[i]) - 1;
        }

        cout << res;
    }

    return 0;
}