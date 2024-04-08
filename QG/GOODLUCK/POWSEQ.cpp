#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n, t;
ll res = 0;
vector<int> a;
vector<unordered_map<int, int>> freq;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> t;
    a.assign(n+1, 0);
    freq.resize(n+1);

    FOR(i, 1, n) {
        cin >> a[i];
        freq[i] = freq[i-1];
        freq[i][a[i]]++;
    }

    while (t--) {
        res = 0;
        int u, v;
        cin >> u >> v;

        for (auto const &i : freq[v]) {
            ll num_of_el = i.second - freq[u-1][i.first];
            if (num_of_el == 0) continue;
            res += (ll)num_of_el * num_of_el * i.first;
        }

        cout << res << el;
    }

    return 0;
}