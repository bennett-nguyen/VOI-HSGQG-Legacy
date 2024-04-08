#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxr = 1e3+1, maxc = 1e3+1;

int r, c;
int board[maxr][maxc];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> r >> c;
    FOR(i, 1, r) {
        FOR(j, 1, c) {
            cin >> board[i][j];
        }
    }

    ll ans = 0;

    FOR(c1, 1, c-1) {
        FOR(c2, c1+1, c) {
            ll mx1 = LLONG_MIN, mx2 = LLONG_MIN;

            FOR(i, 1, r) {
                ll tmp = board[i][c1] + board[i][c2];

                if (tmp > mx1) {
                    mx2 = mx1;
                    mx1 = tmp;
                } else {
                    mx2 = max(mx2, tmp);
                }
            }

            ans = max(ans, mx1+mx2);
        }
    }
    
    cout << ans;
    return 0;
}