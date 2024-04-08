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
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        Line A12(Point(x1, y1), Point(x2, y2));
        Line A34(Point(x3, y3), Point(x4, y4));

        if (are_intersect(A12, A34)) {
            cout << "YES" << el;
        } else {
            cout << "NO" << el;
        }


    }
    
    return 0;
}