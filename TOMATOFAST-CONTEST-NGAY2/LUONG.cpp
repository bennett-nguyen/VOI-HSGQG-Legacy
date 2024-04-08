#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1001;
using pii = pair<int, int>;

int num_nodes, num_edges, s, t;
int df[maxn];
int trace[maxn];
int cost[maxn][maxn], f[maxn][maxn];
vector<pii> dsk[maxn];

bool found_path() {
    queue<int> q;
    q.push(s);
    memset(trace, 0, sizeof(trace));
    trace[s] = -1;
    df[s] = 1e9;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        FOR(v, 1, num_nodes) {
            if (cost[u][v] > f[u][v] && trace[v] == 0) {
                trace[v] = u;
                q.push(v);
                df[v] = min(df[u], cost[u][v] - f[u][v]);
                if (v == t) return true;
            }
        }
    }

    return false;
}

void increase_flow() {
    int qf = df[t];
    int v = t;

    while (trace[v] > 0) {
        int u = trace[v];
        f[u][v] += qf;
        f[v][u] -= qf;
        v = u;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> num_nodes >> num_edges >> s >> t;
    FOR(i, 1, num_edges) {
        int u, v, w;
        cin >> u >> v >> w;
        dsk[u].push_back(make_pair(v, w));
        cost[u][v] = w;
    }

    while (found_path()) increase_flow();
    int max_flow = 0;
    FOR(i, 1, num_nodes) max_flow += f[s][i];
    cout << max_flow;

    return 0;
}