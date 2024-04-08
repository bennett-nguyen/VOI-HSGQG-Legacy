#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int MAXN = 1e5+1;
vector<int> bit;
int n, q;

int get(int idx) {
    int ret = 0;

    while (idx > 0) {
        ret += bit[idx];
        idx -= idx & -idx;
    }

    return ret;
}

int sum(int l, int r) {
    return get(r) - get(l-1);
}

void add(int idx, int delta) {
    while (idx <= n) {
        bit[idx] += delta;
        idx += idx & -idx;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    bit.assign(n+1, 0);

    int x, y, k;

    FOR(i, 1, n) {
        cin >> x;
        add(i, x);
    }
    
    while (q--) {
        cin >> x >> y >> k;
        if (x == 1) {
            add(y, k);
        } else {
            cout << sum(y, k) << ' ';
        }
    }
    
    return 0;
}
