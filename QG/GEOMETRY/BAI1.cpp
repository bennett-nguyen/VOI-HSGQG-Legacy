#include <bits/stdc++.h>
#include "../lib/libgeometry.hpp"
using namespace std;
using namespace Geometry;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n;

    FOR(i, 1, n) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        Point P1(x1, y1), P2(x2, y2), P3(x3, y3);
        if (CCW(P1, P2, P3)) {
            cout << "LEFT" << el;
        } else if (CW(P1, P2, P3)) {
            cout << "RIGHT" << el;
        } else {
            cout << "TOUCH" << el;
        }
    }

    return 0;
}