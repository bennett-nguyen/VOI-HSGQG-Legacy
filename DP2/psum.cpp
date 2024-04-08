#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

ll n, q;
ll arr[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    FOR(i, 1, n) {
        ll tmp;
        cin >> tmp;

        arr[i] = arr[i-1]+tmp;
    }

    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << arr[v] - arr[u-1] << el;
    }
    
    return 0;
}