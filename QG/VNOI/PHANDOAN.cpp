#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;
int n, k, M = 0;
int arr[MAXN], psum[MAXN];
int f[MAXN], g[MAXN];

int bin_search() {
    int L = -1e9, R = 1e9, W = 0;
    
    while (L <= R) {
        W = (L+R)/2;

        FOR(i, 1, n) {
            f[i] = 1e9;
            g[i] = -1e9;

            FOR(j, 0, i-1) {
                if (psum[i] - psum[j] <= W) {
                    f[i] = min(f[i], f[j]+1);
                    g[i] = max(g[i], g[j]+1);
                }
            }
        }

        if (L == R) {
            return W;
        } else if (f[n] <= k && k <= g[n]) {
            R = W;
        } else {
            L = W+1;
        }
    }

    return W;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    cout << bin_search();

    return 0;
}