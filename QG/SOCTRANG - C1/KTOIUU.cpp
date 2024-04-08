#include <bits/stdc++.h>
using namespace std;

#define el endl
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXRC = 333;
const int MAXK = 111;
const int MOD = 22071997;

int r, c, k;
int arr[MAXRC][MAXRC];
int F[MAXRC][MAXRC][MAXK];
int D[MAXRC][MAXRC];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    #ifdef ONLINE_JUDGE
    freopen("k-max.inp", "r", stdin);
    freopen("k-max.out", "w", stdout);
    #endif

    cin >> r >> c >> k;

    FOR(i, 1, r) {
        FOR(j, 1, c) {
            cin >> arr[i][j];
        }
    }

    D[1][1] = arr[1][1];

    // QHD: MANG D
    FOR(i, 2, r) {
        D[i][1] = D[i-1][1] + arr[i][1];
    }

    FOR(i, 2, c) {
        D[1][i] = D[1][i-1] + arr[1][i];
    }

    FOR(i, 2, r) {
        FOR(j, 2, c) {
            D[i][j] = max({D[i][j], D[i-1][j]+arr[i][j], D[i][j-1]+arr[i][j]});
        }
    }

    // QHD: MANG F
    F[1][1][0] = 1;
    
    FOR(i, 1, r) {
        FOR(j, 1, c) {
            FOR(t, 0, k) {
                int cur = D[i][j] - t;
                if (j < c) {
                    int new_t = D[i][j+1] - (cur+arr[i][j+1]);
                    if (new_t <= k) add(F[i][j+1][new_t], F[i][j][t]);
                }

                if (i < r) {
                    int new_t = D[i+1][j] - (cur+arr[i+1][j]);
                    if (new_t <= k) add(F[i+1][j][new_t], F[i][j][t]);
                }
            }
        }
    }

    int res = 0;
    FOR(t, 0, k) {
        add(res, F[r][c][t]);
    }

    cout << D[r][c] << '\n';
    cout << res; 


    return 0;
}