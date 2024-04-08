#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct Ca {
    int w, d, a;
};

struct CanCau {
    int x, c;
};

int n, m, b;

vector<Ca> c;
vector<CanCau> cc;
int max_day_cau = INT_MIN;

void docf() {
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    #ifdef ONLINE_JUDGE
    freopen("fishing.inp", "r", stdin);
    freopen("fishing.OUT", "w", stdout);
    #endif

    cin >> n;

    FOR(i, 1, n) {
        int w, d, a;
        cin >> w >> d >> a;
        c.push_back({w, d, a});
        max_day_cau = max(max_day_cau, d);
    }

    cin >> m;

    FOR(i, 1, m) {
        int x, c;
        cin >> x >> c;
        cc.push_back({x, c});
    }

    
    cin >> b;
}

int max_res = INT_MIN;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    docf();

    for (auto const &can_cau : cc) {
        int res = - can_cau.c - (max_day_cau * b);

        for (auto const &ca : c) {
            if (can_cau.x >= ca.w) {
                res += ca.a;
            }
        }

        max_res = max(max_res, res);
    }

    cout << max_res;
    return 0;
}