#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1001;

int r, c, h, w;
ll board[maxn][maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> r >> c >> h >> w;

    FOR(i, 1, r) {
        FOR(j, 1, c) {
            ll tmp;
            cin >> tmp;
            board[i][j] = board[i-1][j]+board[i][j-1]-board[i-1][j-1]+tmp;
        }
    }

    FOR(p, h, r) {
        FOR(q, w, c) {
            int i = p-h+1;
            int j = q-w+1;

            
        }
    }
    return 0;
}