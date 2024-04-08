#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

ll L, R;
unordered_map<ll, bool> is_prime;

namespace sub1 {
    void sieve() {
        FOR(i, 0, 108) is_prime[i] = true;
        is_prime[0] = is_prime[1] = false;

        for (ll i = 2; i*i <= 108; i++) {
            if (is_prime[i] == false) continue;

            for (ll j = i*i; j <= 108; j += i) {
                is_prime[j] = false;
            }
        }
    }

    bool is_palin(ll num) {
        if (num < 10) return true;

        ll tmp = num;
        ll rever = 0;

        while (tmp) {
            rever = (rever * 10) + (tmp % 10);
            tmp /= 10;
        }

        return num == rever;
    }

    ll sum_digit(ll num) {
        ll res = 0;

        while (num) {
            res += num % 10;
            num /= 10;
        }

        return res;
    }

    ll cnt = 0;
    void driver() {
        sieve();

        FOR(i, L, R) {
            cnt += (is_prime[sum_digit(i)] && is_palin(i));
        }

        cout << cnt;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
    freopen("PALINPRIME.inp", "r", stdin);
    freopen("PALINPRIME.out", "w", stdout);

    cin >> L >> R;  
    sub1::driver();

    return 0;
}