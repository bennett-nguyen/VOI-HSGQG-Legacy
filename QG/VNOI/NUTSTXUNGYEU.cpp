#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 10001;

int num_nodes, num_edges, s, t;
vector<int> dsk[MAXN];
bool visited[MAXN];

namespace sub1 {
    bool BFS(int blocked) {
        queue<int> q;
        memset(visited, 0, sizeof(visited));
        q.push(s);

        while (!q.empty()) {
            int current = q.front(); q.pop();

            for (auto const &child : dsk[current]) {
                if (visited[child] || child == blocked) continue;
                if (child == t) return false;
                q.push(child);
                visited[child] = true;
            }
        }

        return true;
    }

    void driver() {
        int res = 0;
        FOR(i, 1, num_nodes) {
            if (i == s || i == t) continue;
            res += sub1::BFS(i);
        }

        cout << res;
    }
}

namespace AC {
    void driver() {
        
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> num_nodes >> num_edges >> s >> t;
    
    FOR(i, 1, num_edges) {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
    }

    if (num_nodes <= 100) {
        sub1::driver();
    } else {
        AC::driver();
    }

    return 0;
}