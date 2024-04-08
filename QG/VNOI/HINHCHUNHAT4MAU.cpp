#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n;
int xmin = INT_MAX, ymin = INT_MAX, xmax = INT_MIN, ymax = INT_MAX;
map<pair<int, int>, int> a, b;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    FOR(i, 1, n) {
        int x, y, c;
        cin >> x >> y >> c;
        xmax = max(xmax, x);
        xmin = min(xmin, x);
        ymax = max(ymax, y);
        ymin = min(ymin, y);
        a[make_pair(x, y)] = c;
    }

    int res = 0;
    FOR(x1, xmin, xmax) {
        FOR(x2, x1+1, xmax) {
            FOR(y, ymin, ymax) {
                int d1 = a[make_pair(x1, y)];
                int d2 = a[make_pair(x2, y)];
                if ((d1 == 1 && d2 == 2) || ((d1 == 2 && d2 == 1))) {
                    res += b[make_pair(3, 4)];
                    b[make_pair(1, 2)]++;
                    b[make_pair(2, 1)]++;
                } else if ((d1 == 2 && d2 == 3) || ((d1 == 3 && d2 == 2))) {
                    res += b[make_pair(1, 4)];
                    b[make_pair(2, 3)]++;
                    b[make_pair(3, 2)]++;
                } else if ((d1 == 3 && d2 == 4) || ((d1 == 4 && d2 == 3))) {
                    res += b[make_pair(1, 2)];
                    b[make_pair(3, 4)]++;
                    b[make_pair(4, 3)]++;
                } else if ((d1 == 1 && d2 == 4) || ((d1 == 4 && d2 == 1))) {
                    res += b[make_pair(2, 3)];
                    b[make_pair(1, 4)]++;
                    b[make_pair(4, 1)]++;
                }
            }
        }
    }

    cout << res;

    return 0;
}