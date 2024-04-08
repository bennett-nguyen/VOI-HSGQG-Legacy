#include <bits/stdc++.h>
using namespace std;

#define ll long long unsigned
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

int n, res = INT_MIN, ans = 0;
int arr[MAXN], d[MAXN];
int in[MAXN];
bool visited[MAXN];
map<ll, int> mp;
vector<int> dsk[MAXN];

void DFS(int u) {
    visited[u] = true;

    for (auto const &v : dsk[u]) {
        if (visited[v]) continue;
        d[v] = max(d[v], d[u]+1);
        DFS(v);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n;
    FOR(i, 1, n) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    sort(arr+1, arr+1+n);

    FOR(i, 1, n) {
        FOR(j, 1, i-1) {
            int u = arr[i];
            int v = arr[j];
            if (mp[u+v] != 0) {
                dsk[mp[u]].push_back(mp[u+v]);
                dsk[mp[v]].push_back(mp[u+v]);
                in[mp[u+v]]++;
            }
        }
    }

    FOR(i, 1, n) d[i] = 1;
    FOR(i, 1, n) {
        memset(visited, 0, sizeof(visited));
        DFS(i);
        FOR(j, 1, n) res = max(res, d[j]);
    }

    cout << res;
}