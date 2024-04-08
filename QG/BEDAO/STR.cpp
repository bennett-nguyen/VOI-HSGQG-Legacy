#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 2e5+1;

int n, Q;
string S;
vector<int> dsk[MAXN];
int d1[MAXN];

void BFS_1_den_x() {
    queue<int> q;
    bool visited[MAXN];

    visited[1] = true;
    d1[1] = 1;
    q.push(1);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (auto const &v : dsk[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
            d1[v] = d1[u]+1;
        }
    }
}

void BFS(int u, string sq) {
    string ans = sq;
    sq = ' ' + sq;
    queue<int> q;

    bool visited[MAXN];
    visited[u] = true;

    int d[MAXN];
    d[u] = 1;

    string duong_di[MAXN];
    duong_di[u] = sq[d[u]];

    int res = 0;

    q.push(u);
    while (q.size()) {
        int u = q.front();
        q.pop();

        for (auto const &v : dsk[u]) {
            if (d[u]+1 > sq.size()) continue;
            if (visited[v] || S[v] != sq[d[u]+1]) continue;

            d[v] = d[u]+1;
            visited[v] = true;
            duong_di[v] = duong_di[u] + sq[d[v]];

            if (duong_di[v] == ans) {
                res++;
                continue;
            } else {
                q.push(v);
            }
        }
    }

    cout << res << '\n';
}

void docf() {
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    #ifdef ONLINE_JUDGE
    freopen("str.inp", "r", stdin);
    freopen("str.out", "w", stdout);
    #endif

    cin >> n >> Q;
    cin >> S;

    S = ' ' + S;

    FOR(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
        dsk[v].push_back(u);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    docf();

    BFS_1_den_x();

    while (Q--) {
        int u;
        string sq;
        cin >> u >> sq;
        BFS(u, sq);
    }

    return 0;
}