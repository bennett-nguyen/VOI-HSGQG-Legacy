#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int N = 1e6+5;
int n, k;
int a[N];
vector<ll> bit;

ll sum(int idx) {
    ll s = 0;

    while (idx > 0) {
        s += bit[idx];
        idx -= idx & -idx;
    }

    return s;
}

void add(int idx) {
    while (idx <= 2*N) {
        bit[idx]++;
        idx += idx & -idx;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("sotrungvi.inp", "r", stdin);
    freopen("sotrungvi.out", "w", stdout);
    // freopen("a.inp", "r", stdin);

    cin >> n >> k;
    bit.assign(2*N+5, 0);

    FOR(i, 1, n) {
        cin >> a[i];
        a[i] = a[i] >= k ? 1 : -1;
    }

    ll ans = 0, s = 0;
    add(N);

    FOR(i, 1, n) {
        s += a[i];
        ans += sum(s+N);
        add(s+N);
    }
    
    cout << ans << endl;
    return 0;
}
