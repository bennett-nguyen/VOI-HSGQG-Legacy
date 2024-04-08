#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e4+1;

int n, m, S;
set<int> dsk[MAXN];
set<pair<int, int>> st;
int d[MAXN], cnt[MAXN], parent[MAXN];
queue<int> q;

void BFS() {
    FOR(i, 1, n) parent[i] = -1;
    cnt[S] = 1;
    parent[S] = 0;
    q.push(S);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (auto const &v: dsk[u]) {
            if (parent[v] == -1) {
                parent[v] = u;
                d[v] = d[u]+1;
                cnt[v] = cnt[u];
                q.push(v);
            } else if (d[v] == d[u]+1) {
                cnt[v]++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> m >> S;

    while (m--) {
        int u, v;
        cin >> u >> v;
        dsk[u].insert(v);
    }

    BFS();

    int res = 0;
    FOR(i, 1, n) {
        if (cnt[i] >= 2) {
            res++; 
        }
    }

    cout << res;
    return 0;
}