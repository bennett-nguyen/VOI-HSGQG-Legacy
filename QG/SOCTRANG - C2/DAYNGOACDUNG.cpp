#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

#define MASK(x) (1LL << x)
#define BIT_STATE(x, i) ((x >> i) & 1)
#define SET_ON(x, i) (x | MASK(i))
#define SET_OFF(x, i) (x & ~MASK(i))
#define NUM_BITSET(x) __builtin_popcount(x)

string s;

int NUM_BITUNSET(int x) {
    int cnt = 0;

    while (x) {
        if (!(x & 1)) {
            cnt++;
        }

        x = x >> 1;
    }

    return cnt;
}

bool check(string t) {
    int nl = 0, nr = 0;
    for (auto const &c : t) {
        if (nl < nr) return false;
        if (c == '(') nl++;
        else nr++;
    }

    return true;
}

namespace sub1 {
    int ans = 0;
    vector<int> pre_pos;

    void run() {
        int T = MASK(s.size()) - 1;

        FOR(i, 1, T) {
            int num_bs = NUM_BITSET(i);
            int num_bus = NUM_BITUNSET(i);
            if (num_bs != num_bus || num_bs + num_bus != s.size()) continue;

            int cnt = 0;
            int j = i;
            string tmp = "";

            while (j) {
                int bit = j & 1;

                if (bit == 1) {
                    tmp = '(' + tmp;
                } else {
                    tmp = ')' + tmp;
                }

                j >>= 1;
            }
            
            bool ok = true;

            for (auto const &k : pre_pos) {
                if (tmp[k] != s[k]) {
                    ok = false;
                    break;
                } 
            }

            if (!ok) continue;
            if (check(tmp)) ans++;
        }

        cout << ans;
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("brackets.inp", "r", stdin);
    freopen("brackets.out", "w", stdout);
    #endif
    
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '?') {
            sub1::pre_pos.push_back(i);
        }
    }

    if (s.front() == ')' || s.back() == '(' || s.size() % 2 == 1) {
        cout << 0;
        return 0;
    }

    if (s.size() <= 20) {
        sub1::run();
    } else {
            
        // sub2::run();
    }
    return 0;
}