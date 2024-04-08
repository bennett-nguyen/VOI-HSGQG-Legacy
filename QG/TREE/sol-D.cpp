#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(ll i = a; i < b; i++)
const int MAXN = 1e5+1;

ll n, m, d;
vector<ll> dsk[MAXN];
ll LM[3][MAXN], Affac[MAXN], Down[MAXN], Up[MAXN], parent[MAXN];

void DFS_D(ll u) {
    ll v;
    Down[u] = Affac[u] ? 0 : INT_MIN;

    LM[1][u] = INT_MIN;
    LM[2][u] = INT_MIN;

    for (auto const &v : dsk[u]) {
        if (v == parent[u]) continue;

        parent[v] = u;
        DFS_D(v);

        if (Down[v] > LM[2][u]) {
            if (Down[v] > LM[1][u]) {
                LM[2][u] = LM[1][u];
                LM[1][u] = Down[v];
            } else LM[2][u] = Down[v];

            Down[u] = LM[1][u]+1;
        }
	}		
}

void DFS_U(ll v) {
	ll u;
	if (v == 1) {
		if (Affac[1]) Up[1] = 0;
		else Up[1] = INT_MIN;
	} else {
		u = parent[v];
		Up[v] = Up[u]+1;
		if ((Affac[v]) && (Up[v] < 0)) Up[v] = 0;

		if (LM[1][u] == Down[v]) Up[v] = max(Up[v], LM[2][u]+2);
		else Up[v] = max(Up[v], LM[1][u]+2);
	}

	for (auto const &k : dsk[v]) {
        if (k == parent[v]) continue;
        DFS_U(k);
    }
}

int main()
{
	// freopen("a.inp", "r", stdin);
 	// freopen("book.out","w",stdout);

    ll x, y;
	cin >> n >> m >> d;

    FOR(i, 0, m) {
        cin >> x;
        Affac[x] = 1;
    }

	FOR(i, 0, n-1) {
		cin >> x >> y;
        dsk[x].push_back(y);
		dsk[y].push_back(x);
    }

	DFS_D(1);
	DFS_U(1);

	ll ress = 0;

	FOR(i, 1, n+1) {
        if ((Down[i] <= d) && (Up[i] <= d)) ress++;
    }

	cout << ress;
}
