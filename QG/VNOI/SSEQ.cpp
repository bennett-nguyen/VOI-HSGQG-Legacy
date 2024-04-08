#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

struct re {
    int x, y, k;
};

int n, ans = INT_MIN;
re a[MAXN];
int X[MAXN], Y[MAXN];

void sub1() {
    FOR(i, 1, n) {
        cin >> a[i].x >> a[i].y >> a[i].k;
        X[i] = a[i].x;
        Y[i] = a[i].y;
    }

    sort(X+1, X+1+n);
    sort(Y+1, Y+1+n);

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (X[i] < Y[j]) {
                int res = 0;

                FOR(k, 1, n) {
                    if (a[k].x >= X[i] && a[k].y <= Y[j]) {
                        res += a[k].k;
                    }
                }

                ans = max(ans, res);
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    if (n <= 2000) {
        sub1();
    }

    return 0;
}