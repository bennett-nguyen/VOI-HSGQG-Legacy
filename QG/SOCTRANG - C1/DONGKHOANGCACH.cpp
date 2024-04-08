#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 51;

struct re {
    int v, w;
};

vector<int> ans({1, 2});
vector<int> res;
vector<re> dsk[MAXN];
map<int, int> cntDist, node[MAXN];
int high[MAXN];
int n;

void DFS(int u, int par, int root) {
    node[root][high[u]] = u;

    for (auto const &i : dsk[u]) {
        int v = i.v;
        int w = i.w;

        if (v == par) continue;
        high[v] = high[u] + w;
        DFS(v, u, root);
    }
}

vector<int> choose_root(int p) {
    cntDist.clear();
    FOR(i, 1, n) node[i].clear();

    for (auto const &i : dsk[p]) {
        int u = i.v;
        int w = i.w;
        high[u] = w;
        DFS(u, p, u);

        for (auto const &j : node[u]) {
            cntDist[j.first]++;
        }
    }

    int best = 0, dist = 0;

    for (auto const &i : cntDist) {
        if (i.second > best) {
            best = i.second;
            dist = i.first;
        }
    }

    vector<int> tmp;
    for (auto const &i : dsk[p]) {
        if (node[i.v].find(dist) != node[i.v].end()) {
            tmp.push_back(node[i.v][dist]);
        }
    }

    return tmp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("egalitarianism3.inp", "r", stdin);
    freopen("egalitarianism3.out", "w", stdout);
    #endif

    cin >> n;

    FOR(i, 1, n) {
        int u, v, w;
        cin >> u >> v >> w;
        dsk[u].push_back({v, w});
        dsk[v].push_back({u, w});
    }


    FOR(i, 1, n) {
        res = choose_root(i);
        if (res.size() > ans.size()) {
            ans = res;
        }
    }

    cout << ans.size() << el;
    for (auto const &i : ans) {
        cout << i << ' ';
    }

    return 0;
}