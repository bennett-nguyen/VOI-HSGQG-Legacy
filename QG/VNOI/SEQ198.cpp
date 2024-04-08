#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

#define MASK(x) (1LL << x)
#define BIT_STATE(x, i) (x & MASK(i))
#define SET_ON(x, i) (x | MASK(i))
#define SET_OFF(x, i) (x & ~MASK(i))
#define NUM_BITSET(x) __builtin_popcount(x)

const int MAXM = 2001;

int T;
int m, res = INT_MAX;
int arr[MAXM], d[MAXM];
int sz = 0;

int kt(int state) {
    vector<int> cau_hinh;

    FOR(i, 1, m) {
        if (BIT_STATE())
    }
}

void sub1() {
    T = MASK(m) - 1;

    FOR(i, 1, T) {
        int ans = kt(i);
        if (ans) res = min(res, ans);
    }

    if (res == INT_MAX) cout << 0;
    else cout << res;
}

void sub2() {
    sort(arr+1, arr+1+m);
    int m = 1;
    d[1] = 1;

    FOR(i, 2, m) {
        if (arr[i] != arr[m]) {
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> m;
    FOR(i, 1, m) cin >> arr[i];

    if (m <= 20) sub1();
    else sub2();
    return 0;
}