#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1001;

int trai[MAXN], phai[MAXN];
bool visited[MAXN];
vector<int> dsk[MAXN];

int x, y, m;

bool ghep_duoc(int i) {
    if (visited[i]) return false;
    visited[i] = true;

    for (auto const &j : dsk[i]) {
        if (phai[j] == 0 || ghep_duoc(phai[j])) {
            trai[i] = j;
            phai[j] = i;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> x >> y >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
    }

    int cnt = 0;
    FOR(i, 1, x) {
        memset(visited, 0, sizeof(visited));
        cnt += ghep_duoc(i);
    }

    cout << cnt;
    
    return 0;
}