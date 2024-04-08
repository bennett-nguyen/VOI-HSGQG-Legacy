#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n, maxn = INT_MIN;
int res = INT_MIN, d = 0;

struct re {
    int u, w;
};

set<int> dau, dit;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    // freopen("meeting.inp", "r", stdin);
    // freopen("meeting.out", "w", stdout);
    
    cin >> n;

    FOR(i, 1, n) {
        int x, y;
        cin >> x >> y;
        maxn = max(maxn, max(x, y));
        dau.insert(x);
        dit.insert(y);
    }

    FOR(i, 0, maxn) {
        if (dau.find(i) != dau.end()) {
            d++;
            res = max(res, d);
        }

        if (dit.find(i) != dit.end()) {
            d--;
        }
    }

    cout << res;
    return 0;
}