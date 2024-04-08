#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define int long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

int n, res = 0;
int arr[maxn];

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> n;
    FOR(i, 0, n-1) cin >> arr[i];
    
    FOR(i, 0, n-1) {
        FOR(j, i+1, n-1) {
            res += arr[i] ^ arr[j];
        }
    }

    cout << res;
    return 0;
}