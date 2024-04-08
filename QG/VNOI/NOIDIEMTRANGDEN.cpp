#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

int n;
int a[MAXN], b[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    sort(a+1, a+1+n);
    sort(b+1, b+1+n);

    FOR(i, 1, n) {
        
    }
    return 0;
}