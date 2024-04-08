#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

int n, t;
unordered_map<pair<int, int>, int> mp;
vector<int> dsk[maxn];

namespace sub1 {
    bool visited[maxn];

    bool BFS(int start, int end) {
        queue<int> q;
        memset(visited, 0, sizeof(visited));
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto const &v : dsk[u]) {
                if (visited[v]) continue;
                visited[v] = true;
                q.push(v);

                if (v == end) {
                    mp[make_pair(start, end)] = 2;
                    mp[make_pair(end, start)] = 1;
                }
            }

            mp[make_pair(start, end)] = 1;
        }
    }

    void driver() {

    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> t;
    FOR(i, 1, n) {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
        mp[make_pair(u, v)] = 2;
        mp[make_pair(v, u)] = 1;
    }

    if (n <= 300) {
        sub1::driver();
    }

    return 0;
}