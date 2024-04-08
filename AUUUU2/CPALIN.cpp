#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

string s;
int q;

namespace sub1 {
    bool checker() {
        return s.size() <= 100;
    }

    bool is_palin(int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    void driver() {
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (is_palin(l, r)) {
                cout << "yes" << el;
            } else {
                cout << "no" << el;
            }
        }
    }
}

namespace sub2 {
    map<pair<int, int>, int> dp;

    int DP(pair<int, int> seg) {
        if (dp[seg] != -1) return dp[seg];
        if (seg.first > seg.second || seg.first < 1 || seg.second > s.size()-1) return dp[seg] = 0;
        if (seg.first == seg.second) return dp[seg] = 1;
        if (seg.first+1 == seg.second) return dp[seg] = (s[seg.first] == s[seg.second]);

        if (s[seg.first] == s[seg.second]) return dp[seg] = DP(make_pair(seg.first+1, seg.second-1));
        return dp[seg] = 0;
    }

    void driver() {
        FOR(i, 1, s.size()-1) {
            FOR(j, i, s.size()-1) {
                if (i == j) dp[make_pair(i, j)] = 1;
                else dp[make_pair(i, j)] = -1;
            }
        }

        while (q--) {
            pair<int, int> seg;
            cin >> seg.first >> seg.second;

            if (DP(seg) == 1) {
                cout << "yes" << el;
            } else {
                cout << "no" << el;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("CPALIN.inp", "r", stdin);
    freopen("CPALIN.out", "w", stdout);
    #endif
    
    getline(cin, s);
    s = ' ' + s;
    cin >> q;

    if (sub1::checker()) return sub1::driver(), 0;
    else sub2::driver();

    return 0;
}