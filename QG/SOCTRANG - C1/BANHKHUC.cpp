#include <bits/stdc++.h>
using namespace std;

#define el endl
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)
#define BIT(mask, i) ((mask >> i) & 1)
const int MAXN = 501;

int n, k;
int C[MAXN][MAXN];
ll F[1 << 20][20];
vector<int> x;

void Floyd() {
    FOR(k, 1, n) {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("banhkhuc.inp", "r", stdin);
    freopen("banhkhuc.out", "w", stdout);

    cin >> n >> k;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> C[i][j];
        }
    }

    FOR(i, 1, k) {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }

    Floyd();
    memset(F, 0x3f, sizeof(F));

    FOR(i, 0, k-1) {
        F[1<<i][i] = C[1][x[i]];
    }

    FOR(mask, 0, (1<<k)-1) {
        FOR(i, 0, k-1) {
            if (BIT(mask, i)) {
                FOR(j, 0, k-1) {
                    if (!BIT(mask, j)) {
                        F[mask|(1<<j)][j] = min(F[mask|(1<<j)][j], F[mask][i]+C[x[i]][x[j]]);
                    }
                }   
            }
        }
    }

    ll res = INT_MAX;

    FOR(i, 0, k-1) {
        res = min(res, F[(1<<k)-1][i] + C[x[i]][1]);
    }

    cout << res;
    return 0;
}