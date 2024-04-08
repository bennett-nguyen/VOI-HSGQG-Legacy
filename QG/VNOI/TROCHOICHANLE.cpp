#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 501;

int T;
int arr[maxn][maxn];

// first: cong don hang
// second: cong don cot
pair<int, int> psum[maxn][maxn];
bool dp[maxn][maxn];

bool DP(int i, int j) {
    dp[i][j] = (
        (DP(i-1, j) == false && psum[i][j].second-psum[i][0].second % 2 == 0) ||
        (DP(i, j-1) == false && psum[i][j].first-psum[0][j].first % 2 == 0)
    );

    return dp[i][j];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                cin >> arr[i][j];
            }
        }

        FOR(i, 1, n) {
            FOR(j, 1, n) {
                psum[i][j].first = psum[i][j-1].first+arr[i][j];
            }
        }

        FOR(c, 1, n) {
            FOR(r, 1, n) {
                psum[r][c].second = psum[r-1][c].second+arr[r][c];
            }
        }

        cout << (DP(n, n) ? "YES" : "NO") << el;
    }

    return 0;
}