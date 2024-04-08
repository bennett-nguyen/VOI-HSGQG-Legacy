#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define INF 1e16
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)
#define sz(x) ((int)x.size())

int d;
vector<int> v;

namespace FULL_AC {
    ll cal(vector<int> vt) {
        if (sz(vt) <= 1) {
            return 0;
        }

        int mid = (sz(vt) - 1) / 2;
        vector<int> v1, v2;

        FOR(i, 0, mid) v1.push_back(vt[i]);
        FOR(i, mid+1, sz(vt)-1) v2.push_back(vt[i]);

        ll res = cal(v1) + cal(v2);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        ll best = INF, cnt = 0;

        for (int i = 0, j = 0; i < sz(v1); i++) {
            while (j < sz(v2) && v1[i] > v2[j]) j++;
            cnt += j;
        }

        best = min(best, cnt);
        cnt = 0;

        for (int i = 0, j = 0; i < sz(v2); i++) {
            while (j < sz(v1) && v2[i] > v1[j]) j++;
            cnt += j;

            if (cnt > best) break;
        }

        best = min(best, cnt);
        return best + res;
    }

    void run() {
        cout << cal(v);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> d;

    int tmp;
    while (cin >> tmp) v.push_back(tmp);

    FULL_AC::run();
    return 0;
}