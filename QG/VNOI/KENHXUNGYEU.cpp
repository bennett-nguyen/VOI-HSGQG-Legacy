#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct re {
    int v;
    bool is_deleted = false, is_xung_yeu = false; 
};

int n, m, sl = 0;
vector<re> dsk[10001];
int color[10001];
int parent[10001];
vector<re> canh;

void dfs(int u) {
    color[u] = GRAY;
    for (auto const &v : dsk[u]) {
        if (sl) break;
        if (v.is_deleted) continue;

        if (color[v.v] == GRAY) {
            sl++;
            break;
        }

        if (color[v.v] == WHITE) {
            dfs(v.v);
        }
    }

    color[u] = BLACK;
}

bool exist_cycle() {
    memset(color, 0, sizeof(color));
    sl = 0;

    FOR(i, 1, n) {
        if (sl) break;
        if (color[i] == WHITE) dfs(i);
    }

    return sl > 0;
}

void sub1() {
    int res = 0;

    FOR(i, 1, n) {
        for (auto &v : dsk[i]) {
            v.is_deleted = true;

             if (exist_cycle()) {
                res++;
                v.is_xung_yeu = true;
            }

            v.is_deleted = false;
        }
    }

    if (res <= 0) {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> m;
    while (m--) {
        int u; 
        re tmp;
        cin >> u >> tmp.v;
        dsk[u].push_back(tmp);
    }

    if (!exist_cycle()) {
        cout << -1;
        return 0;
    }

    if (n <= 200) {
        sub1();
    }

    return 0;
}