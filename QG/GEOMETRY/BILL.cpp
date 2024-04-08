#include <bits/stdc++.h>
#include "../lib/libgeometry.hpp"
using namespace std;
using namespace Geometry;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n;
double res = INT_MAX;
Point bill_house;
vector<Point> p;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n;
    cin >> bill_house.x >> bill_house.y;

    FOR(i, 1, n) {
        Point tmp;
        cin >> tmp.x >> tmp.y;
        p.push_back(tmp);
    }

    for (auto const &i : p) {
        res = min(res, dist(i, bill_house));
    }

    FOR(i, 0, p.size()-1) {
        int next = (i+1)%n;
        Line d1(p[i], p[next]);

    }

    
    return 0;
}