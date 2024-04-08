#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;
const int MAXR = 100;

int n;
int arr[MAXN];
vector<int> ok1[MAXR+1], ok2[MAXR+1][MAXR+1], ok3[MAXR+1][MAXR+1][MAXR+1];            
vector<int> kq;

bool check(int x, int y, int z, int t) {
    return (x < y && y < z && z < t && max({y-x, z-y, t-z}) <= 10);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    #ifdef ONLINE_JUDGE
    freopen("problemset.inp", "r", stdin);
    freopen("problemset.out", "w", stdout);
    #endif

    cin >> n;
    FOR(i, 1, n) cin >> arr[i];

    FOR(a, 1, MAXR) {
        FOR(b, a+1, min(MAXR, a+10)) {
            FOR(c, b+1, min(MAXR, b+10)) {
                FOR(d, c+1, min(MAXR, c+10)) {
                    vector<int> tmp({a, b, c, d});
                    ok1[a] = ok1[b] = ok1[c] = ok1[d] = tmp;
                    ok2[a][b] = ok2[a][c] = ok2[a][d] = tmp;
                    ok2[b][c] = ok2[b][d] = ok2[c][d] = tmp;
                    ok3[a][b][c] = ok3[a][b][d] = tmp;
                    ok3[a][c][d] = ok3[b][c][d] = tmp;
                }
            }
        }
    }

    int i = 1;
    int cnt = 0;

    while (i <= n) {
        int x = arr[i], y = arr[i+1], z = arr[i+2], t = arr[i+3];

        if (i+3 <= n && check(x, y, z, t)) {
            FOR(j, 0, 3) {
                kq.push_back(arr[i+j]);
            }

            i += 4;
        } else if (i+2 <= n && !ok3[x][y][z].empty()) {
            FOR(j, 0, 3) {
                kq.push_back(ok3[x][y][z][j]);
            }

            i += 3;
            cnt += 1;
        } else if (i+1 <= n && !ok2[x][y].empty()) {
            FOR(j, 0, 3) {
                kq.push_back(ok2[x][y][j]);
            }

            i += 2;
            cnt += 2;
        } else {
            FOR(j, 0, 3) {
                kq.push_back(ok1[x][j]);
            }

            i++;
            cnt += 3;
        }
    }

    cout << cnt << el;
    for (auto const &i : kq) {
        cout << i << ' ';
    }

    return 0;
}