#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

ll L, R;

namespace sub1 {
    bool is_prime(ll x) {
        if (x < 2) return false;

        for (ll i = 2; i*i <= x; i++) {
            if (x % i == 0) return false;
        }

        return true;
    }

    bool is_palindrome(ll x) {
        ll tmp = x;
        ll palin = 0;

        while (tmp) {
            palin = (palin*10) + (tmp%10);
            tmp /= 10; 
        }

        return x == palin;
    }

    bool check(ll x) {
        ll sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }

        return is_prime(sum);
    }

    void driver() {
        ll cnt = 0;
        FOR(i, L, R) {
            cnt += (check(i) && is_palindrome(i));
        }

        cout << cnt;
    }
}

namespace sub2 {
    bool is_prime(ll x) {
        if (x < 2) return false;

        for (ll i = 2; i*i <= x; i++) {
            if (x % i) continue;
            return false;
        }

        return true;
    }

    ll to_palin(ll x) {
        ll tmp = x;
        ll palin = 0;

        while (tmp) {
            palin = (palin*10) + (tmp%10);
            tmp /= 10;
        }

        return palin;
    }

    bool check(ll x) {
        ll sum = 0;
        while (x) {
            sum += x%10;
            x /= 10;
        }

        return is_prime(sum);
    }

    ll dup(ll x, bool odd) {
        ll res = x;

        if (odd) {
            x /= 10;
        }

        while (x) {
            res = (res*10) + (x%10);
            x /= 10;
        }

        return res;
    }

    void driver() {
        ll cnt = 0;

        for (ll i = 1; i <= 999999; i++) {
            for (int j = 0; j < 2; j++) {
                ll here = dup(i, j);
                if (here < L || here > R) continue;
                cnt += check(here);
            }
        }

        cout << cnt;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> L >> R;

    if (R <= 1e6) {
        sub1::driver();
    } else {
        sub2::driver();
    }

    return 0;
}