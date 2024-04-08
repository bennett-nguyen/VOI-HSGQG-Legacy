#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXM = 101, MAXN = 101, BASE = 1e9;

int n, m;
int arr[MAXM][MAXN];
int f[MAXM][MAXN];

void sub1() {
    FOR(i, 1, m) f[i][1] = 1;

    FOR(i, 1, m) {
        FOR(j, 1, n-1) {
            FOR(x, 1, i) {
                FOR(y, 1, j-1) {
                    if (__gcd(arr[i][j], arr[x][y]) > 1) {
                        f[i][j] = (f[i][j]+f[x][y]) % BASE; 
                    }
                }
            }

            FOR(x, 1, i-1) {
                if (__gcd(arr[i][j], arr[x][j]) > 1) {
                    f[i][j] = (f[i][j]+f[x][j]) % BASE;
                }
            }
        }
    }

    FOR(i, 1, m) {
        FOR(x, 1, i) {
            FOR(y, 1, n-1) {
                if (__gcd(arr[i][n], arr[x][y]) > 1) {
                    f[i][n] = (f[i][n]+f[x][y]) % BASE;
                }
            }
        }
    }

    ll res = 0;
    FOR(i, 1, m) {
        res = (res+f[i][n])%BASE;
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> m >> n;

    FOR(i, 1, m) {
        FOR(j, 1, n) {
            cin >> arr[i][j];
        }
    }

    sub1();
    return 0;
}