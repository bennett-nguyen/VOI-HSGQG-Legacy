#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

// f(x, y, z): so canh ke noi 3 dinh x, y, z
// g(x, y, z): thua so cua gcd(x, y, z)

// d[x, y] + d[y, z] + d[z, x]
// sub1: Floyd

const int MAXN = 200001;

int n;
int w[MAXN];
vector<int> dsk[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n;

    FOR(i, 1, n) cin >> w[i];
    FOR(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
        dsk[v].push_back(u);
    }

    return 0;
}