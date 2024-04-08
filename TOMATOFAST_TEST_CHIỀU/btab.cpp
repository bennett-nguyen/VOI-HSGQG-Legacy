#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxr = 5e6+1, maxc = 5e6+1;

int num_rows, num_columns;
int a[maxr], b[maxc];

namespace sub1 {
    int board[31][31];
    int psum[31][31];

    bool check(int u, int v, int s) {
        int sum_diag = 0;
        FOR(i, 0, s-1) {
            sum_diag += board[u+i][v+i];
        }

        if (sum_diag != s) return false; 

        FOR(i, u, u+s-1) {
            if (psum[i][v+s-1]-psum[i][v-1] != 0)
                return false;
        }

        return true;
    }

    int cnt = 0;
    void driver() {
        FOR(i, 1, num_rows) {
            FOR(j, 1, num_columns) {
                board[i][j] = a[i]*b[j];
                psum[i][j] = psum[i][j-1]+board[i][j];
            }
        }

        
        FOR(k, 2, max(num_rows, num_columns)) {
            FOR(i, 1, num_rows-k+1) {
                FOR(j, 1, num_columns-k+1) {
                    if (!check(i, j, k)) continue;
                    cnt++;
                }
            }
        }

        cout << cnt;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("btab.inp", "r", stdin);
    freopen("btab.out", "w", stdout);
    
    cin >> num_rows >> num_columns;
    FOR(i, 1, num_rows) cin >> a[i];
    FOR(i, 1, num_columns) cin >> b[i];
    sub1::driver();

    return 0;
}