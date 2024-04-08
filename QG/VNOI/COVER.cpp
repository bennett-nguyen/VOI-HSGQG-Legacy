#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct re {
    int x, y; // toa do
    bool t; // dau - dit
};

int n;
vector<re> point;
multiset<int, greater<int>> S;

int res = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;

    FOR(i, 1, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        point.push_back({x1, y1, 0});
        point.push_back({x2, y2, 1});
    }

    sort(point.begin(), point.end(),
        [](const re &a, const re &b) -> bool {
            return (a.x < b.x) || (a.x == b.x && a.t > b.t);
        }
    );

    int x = 0;
    for (auto const &p : point) {
        if (!p.t) {
            int l = *S.begin();
            res += l * (p.x-x);
            x = p.x;
            S.insert(p.y);
        } else {
            int l = *S.begin();
            res += l * p.x - x;
            x = p.x;
            S.erase(S.lower_bound(p.y));
        }
    }

    cout << res;
    return 0;
}