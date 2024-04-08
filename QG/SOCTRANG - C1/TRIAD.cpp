#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el endl
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n, max_ans = -1;

int lcm(int x,int y){
	return (x * y) / __gcd(x, y);
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("a.inp", "r", stdin);
    freopen("lcm.inp", "r", stdin);
    freopen("lcm.out", "w", stdout);

	cin >> n;

	for (int i = n-100; i <= n; i++) {
		if(i <= 0) continue;
		for (int j = n-100; j <= n; j++) {
			if (j <= 0) continue;
			for(int k = n-100; k <= n; k++) {
				if (k <= 0) continue;
				max_ans = max(max_ans, lcm(lcm(i,j), k));
			}
		}
	}

	cout << max_ans;
    return 0;
}
