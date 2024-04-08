#include <bits/stdc++.h>
#include "../lib/bit.hpp"
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 17;

int n;
int C[MAXN][MAXN];
int F[MAXN][MASK(MAXN)];

int calc(int i, int S) {
    if (F[i][S] != INT_MAX) return F[i][S];
    if (S == 1) return F[i][S] = 0;
    if (S == 1 + MASK(i)) return F[i][S] = C[i][0] + C[0][i];

    int res = INT_MAX;
    FOR(j, 0, n-1) {
        if (j == i) continue;
        if (BIT_STATE(S, j)) {
            res = min(res, calc(j, S-MASK(i)) + C[j][i]);
        }
    }

    return F[i][S] = res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> n;

    FOR(i, 0, n-1) {
        FOR(j, 0, n-1) {
            cin >> C[i][j];
        }
    }

    FOR(i, 0, n-1) {
        FOR(S, 0, MASK(n)-1) {
            F[i][S] = INT_MAX;
        }
    }

    FOR(i, 0, n-1) {
        F[i][MASK(i)] = 0;
    int T = MASK(n)-1;
    int ans = INT_MAX;

    FOR(i, 1, n-1) {
        ans = min(ans, calc(i, T));
    }

    cout << ans;
    return 0;
}