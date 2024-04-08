#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

ll n, q;
ll max_ans = LLONG_MIN;
ll d[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> q;

    while (q--) {
        ll l, r, w;
        cin >> l >> r >> w;
        d[l] += w;
        d[r+1] -= w;
    }

    ll tmp = 0;
    FOR(i, 1, n) {
        tmp += d[i];
        max_ans = max(max_ans, tmp);
    }

    cout << max_ans;
    return 0;
}