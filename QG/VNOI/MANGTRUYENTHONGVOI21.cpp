#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1001;

int n, k, a, b;
int c[maxn][maxn];
vector<int> dsk[maxn];

void sub1() {
    int cnt = 0;

    FOR(k, 1, n) {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }

    FOR(i, 1, n) {
        FOR(j, i+1, n) {
            if (a <= c[i][j] && c[i][j] <= b) cnt++;
        }
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> k >> a >> b;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            c[i][j] = 1e8;
        }
    }

    FOR(i, 1, n) {
        c[i][i] = 0;
    }

    FOR(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
        dsk[v].push_back(u);
        c[u][v] = 1;
        c[v][u] = 1;
    }

    if (n <= 100 && k == 2) {
        sub1();
    }

    return 0;
}