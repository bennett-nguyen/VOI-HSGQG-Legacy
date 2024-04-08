#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXT = 1e5+1;
const int MOD = 998244353;

int t, n_max = -1;
int arr[MAXT];
int LCM[MAXT], P[MAXT];
bool prime[MAXT];

void sieve() {
    memset(prime, true, sizeof(prime));
    
    prime[0] = prime[1] = false;
    for (int i = 2; i*i <= t; i++) {
        if (!prime[i]) continue;
        for (int j = i*i; j <= t; j += i) {
            prime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("primelcm.inp", "r", stdin);
    freopen("primelcm.out", "w", stdout);
    #endif

    cin >> t;
    FOR(i, 1, t) {
        cin >> arr[i];
        n_max = max(n_max, arr[i]);
    }

    sieve();
    LCM[1] = arr[1];
    P[1] = 1;

    FOR(i, 2, n_max) {
        LCM[i] = lcm(i, LCM[i-1]);
        if (i == 2) P[i] = 2;
        else {
            if (prime[i]) {
                P[i] = P[i-1] * i;
            } else {
                P[i] = P[i-1];
            }
        }
    }

    cout << P[4];
    // FOR(i, 1, t) {
    //     cout << (LCM[arr[i]]/P[arr[i]]) % MOD << ' ';
    // }

    return 0;
}