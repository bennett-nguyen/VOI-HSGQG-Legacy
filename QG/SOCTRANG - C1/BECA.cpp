#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXRC = 1e6+1;

struct re {
    int r, c, w;
};

int r, c;
string board[MAXRC];
vector<int> top_s[MAXRC], bottom_s[MAXRC], left_s[MAXRC], right_s[MAXRC];
vector<re> cost;

vector<int> parent, sz;

void make_set() {
    parent.assign(4*r*c, 0);
    sz.assign(4*r*c, 0);
    FOR(i, 1, 4*r*c) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find_set(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_set(parent[u]);
}

bool dsu_union(int u, int v) {
    u = find_set(u);
    v = find_set(v);

    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];

    return true;
}

ll res = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("aquarium.inp", "r", stdin);
    freopen("aquarium.out", "w", stdout);
    #endif

    cin >> r >> c;
    make_set();

    FOR(i, 1, r) cin >> board[i];

    int cnt = 0;

    FOR(i, 1, r) {
        top_s[i].assign(c+1, 0), bottom_s[i].assign(c+1, 0), left_s[i].assign(c+1, 0), right_s[i].assign(c+1, 0);

        FOR(j, 1, c) {
            top_s[i][j] = ++cnt, bottom_s[i][j] = ++cnt, left_s[i][j] = ++cnt, right_s[i][j] = ++cnt;
            int w; cin >> w;
            cost.push_back({i, j, w});
        }
    }

    sort(cost.begin(), cost.end(), [](const re &a, const re &b) -> bool { return a.w < b.w; });

    FOR(i, 1, r) {
        FOR(j, 1, c) {
            if (i < r) dsu_union(bottom_s[i][j], top_s[i+1][j]);
            if (j < c) dsu_union(right_s[i][j], left_s[i][j+1]);

            if (board[i][j-1] == '/') {
                dsu_union(top_s[i][j], left_s[i][j]), dsu_union(bottom_s[i][j], right_s[i][j]);
            } else {
                dsu_union(top_s[i][j], right_s[i][j]), dsu_union(bottom_s[i][j], left_s[i][j]);
            }
        }
    }

    for (re const &i : cost) {
        if (board[i.r][i.c-1] == '/') {
            if (dsu_union(top_s[i.r][i.c], right_s[i.r][i.c])) {
                board[i.r][i.c-1] = '.';
                res += i.w;
            }
        } else {
            if (dsu_union(top_s[i.r][i.c], left_s[i.r][i.c])) {
                board[i.r][i.c-1] = '.';
                res += i.w;
            }
        }
    }

    cout << res << el;
    FOR(i, 1, r) cout << board[i] << el;

    return 0;
}