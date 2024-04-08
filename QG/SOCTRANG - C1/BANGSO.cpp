#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define int long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e6+1;
const int MOD = 1e9+7;

int F[MAXN];
int r, c;

void tinh_luy_thua() {
    F[0] = 1;
    FOR(i, 1, 1e6) {
        F[i] = (F[i-1] % MOD * i % MOD) % MOD;
    }
}

int POW(int a, int n) {
    if (n == 1) return a;

    int tmp = POW(a, n/2);
    tmp = (tmp * tmp) % MOD;

    if (n % 2) {
        return (tmp * a) % MOD;
    } else {
        return tmp;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    #ifdef ONLINE_JUDGE
    freopen("matrix.inp", "r", stdin);
    freopen("matrix.out", "w", stdout);
    #endif
    
    cin >> r >> c;
    tinh_luy_thua();

    int a = max(r, c);
    int b = min(r, c);
    
    int x = b, cnt = 1, ans = 1;
    if (a == b) {
        ans = F[a];
        x--;
    }

    FOR(i, 1, x) {
        ans = (ans * F[i]) % MOD;
        ans = (ans * F[i]) % MOD;
    }

    if (a-b-1 > 0) {
        ans = (ans % MOD * POW(F[b], a-b-1) % MOD) % MOD;
    }

    cout << ans;
    return 0;
}