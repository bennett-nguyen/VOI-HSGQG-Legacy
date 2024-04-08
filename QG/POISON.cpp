#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

int n;
ll a[maxn];

namespace sub1 {
    ll min_ans = LLONG_MAX;

    void driver() {
        FOR(j, 2, n) {
            FOR(i, 1, j-1) {
                ll c = (a[i]-a[j]);
                min_ans = min(min_ans, c*c+2*(a[i]+i-a[j]-j)*(i-j));
            }
        }
        cout << min_ans;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    if (n <= 1000) {
        sub1::driver();
    }
    return 0;
}