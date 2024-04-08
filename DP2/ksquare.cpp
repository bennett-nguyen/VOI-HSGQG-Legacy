#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e4+1;

ll n, k;
ll max_ans = LLONG_MIN;
ll board[maxn][maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> k;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            ll tmp; cin >> tmp;
            board[i][j] = board[i-1][j]+board[i][j-1]-board[i-1][j-1]+tmp;
        }
    }

    FOR(p, k, n) {
        FOR(q, k, n) {
            int i = p-k+1;
            int j = q-k+1;

            max_ans = max(max_ans, board[p][q]-board[p][j-1]-board[i-1][q]+board[i-1][j-1]);
        }
    }

    cout << max_ans;
    return 0;
}