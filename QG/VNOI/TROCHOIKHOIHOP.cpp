#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)
#define pii pair<int, int>

const pii d[4] = {
    make_pair(-1, 0),
    make_pair(0, -1),
    make_pair(1, 0),
    make_pair(0, 1)
};

const int MAX = 1001;

int a, b, c, rows, columns, k;
map<pii, bool> blocked;

namespace sub1 {
    queue<pii> q;
    map<pii, bool> visited;
    int res = 1;

    bool check(pii current) {
        return (1 <= current.first && current.first <= rows && 1 <= current.second && current.second <= columns && !blocked[current] && !visited[current]);
    }

    void BFS() {
        q.push(make_pair(1, 1));
        visited[make_pair(1, 1)] = true;

        while (!q.empty()) {
            pii current = q.front();
            q.pop();

            for (auto const &k : d) {
                pii child = make_pair(current.first+k.first, current.second+k.second);
                if (!check(child)) continue;

                res++;
                visited[current] = true;
                q.push(child);
            }
        }
    }

    void driver() {
        BFS();
        cout << res;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> a >> b >> c >> rows >> columns >> k;

    while (k--) {
        int u, v;
        cin >> u >> v;
        blocked[make_pair(u, v)] = true;
    }

    if (a == b && b == c && c == 1) {
        sub1::driver();
    }

    return 0;
}