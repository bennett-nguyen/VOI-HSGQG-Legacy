#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

#define MASK(x) (1LL << x)
#define BIT_STATE(x, i) (x & MASK(i))
#define SET_ON(x, i) (x | MASK(i))
#define SET_OFF(x, i) (x & ~MASK(i))
#define NUM_BITSET(x) __builtin_popcount(x)


int s, n;
vector<int> v; 
map<int, bool> mp;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> s >> n;
    FOR(i, 1, n) {
        int a, b;
        cin >> a >> b;
        vector<int> tmp(b, a);
        v.insert(v.end(), tmp.begin(), tmp.end());
    }

    int res = 0;

    FOR(i, 1, MASK(v.size())-1) {
        int ans = 0;

        FOR(j, 0, v.size()-1) {
            if (BIT_STATE(i, j)) {
                ans += v[j];
            }
        }

        if (!mp[i] && ans == s) {
            res++;
            mp[i] = true;
        }
    }

    cout << res;
    return 0;
}