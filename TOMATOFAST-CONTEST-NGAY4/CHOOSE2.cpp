#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxs = 501; 

int r, c;
int board[maxs][maxs];
int psum[maxs][maxs];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> r >> c;
    FOR(i, 1, r) {
        FOR(j, 1, c) {
            cin >> board[i][j];
            psum[i][j] = psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+board[i][j];
        }
    }

     
    return 0;
}