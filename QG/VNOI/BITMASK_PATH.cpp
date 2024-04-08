#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)
#define MASK(x) (1LL << x)
#define BIT_STATE(x, i) (x & MASK(i))
#define SET_ON(x, i) (x | MASK(i))
#define SET_OFF(x, i) (x & ~MASK(i))

const int MAXN = 16;


ll n; // number of verticies
ll C[MAXN][MAXN]; // cost of each edge

// Let F[i][S] be the shortest path from 0 -> i where i is the currently visited vertex at some state S
ll F[MAXN][MASK(MAXN)];

ll calc(ll i, ll S) {
    if (F[i][S] != INT_MAX) return F[i][S]; // vertex is visited
    if (S == 1) return F[i][S] = 0; // if only vertex 0 were visited 
    if (S == 1 + (1 << i)) return F[i][S] = C[0][i] + C[i][0]; // if we visited vertex 0 AND some vertex i 

    ll res = INT_MAX;

    // looping through all verticies
    FOR(j, 0, n-1) {
        if (j == i) continue; // if vertex was already chosen before
        if (S & MASK(j)) { // if the vertex exist in some state S
            res = min(res, calc(j, S ^ MASK(i)) + C[j][i]);
        }
    }

    return F[i][S] = res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n;

    FOR(i, 0, n-1) {
        FOR(j, 0, n-1) {
            cin >> C[i][j];
        }
    }

    // Base case: the cost of paths to all verticies within all state are infinite
    FOR(i, 0, n-1) {
        FOR(S, 0, MASK(n)-1) {
            F[i][S] = INT_MAX;
        }
    }

    // Base case: the cost of paths to some vertex i where theres only i in such state is 0
    FOR(i, 0, n-1) {
        F[i][MASK(i)] = 0;
    }

    // let T be the set of all verticies
    ll T = MASK(n) - 1;
    ll ans = INT_MAX;
    
    // looping through all verticies that is not 0
    FOR(i, 1, n-1) {
        ans = min(ans, calc(i, T));
    }

    cout << ans;
    return 0;
}