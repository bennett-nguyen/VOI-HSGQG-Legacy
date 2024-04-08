#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long unsigned
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int T;
ll n, k, i;
unordered_map<ll, ll> fib;
vector<ll> q;

namespace sub1 {
    void driver() {
        fib.clear();
        fib[1] = fib[2] = 1;
        for (ll idx = 3; idx < i+n; idx++) {
            fib[idx] = (fib[idx-1]+fib[idx-2])%k;
        }

        for (ll mask = 1; mask <= (ll)(1<<n)-1; mask++) {
            q.clear();  
            ll tmp = mask;
            ll sum = 0;
            ll u = 0;

            while (tmp) {
                if (tmp & 1) {
                    sum += fib[u+i];
                    q.push_back(u+i);
                }

                tmp >>= 1;
                u++;
            }

            if (sum % k == 0 && sum >= k) {
                cout << q.size() << ' ';

                for (auto const &v : q) {
                    cout << v << ' ';
                }

                cout << el;
                return;
            }
        }

        cout << 0 << el;
    }
}

namespace AC {
    unordered_map<ll, ll> f;
    vector<ll> q;

    struct Matrix {
        int R, C;
        vector<vector<ll>> X;

        Matrix(int r, int c) {
            X.assign(r, vector<ll>(c, 0));
            R = r;
            C = c;
        }

        Matrix operator*(Matrix b) {
            Matrix res(R, b.C);

            FOR(u, 0, R-1) {
                FOR(v, 0, b.C-1) {
                    res.X[u][v] = 0;

                    FOR(w, 0, b.R-1) {
                        res.X[u][v] += X[u][w]*b.X[w][v];
                    }

                    res.X[u][v] %= k;
                }
            }

            return res;
        }
    };

    Matrix luy_thua(Matrix a, ll n) {
        if (n == 1) return a;
        Matrix res = luy_thua(a, n>>1);

        if (n % 2) {
            return res * res * a;
        }

        return res * res;
    }

    void driver() {
        f.clear();
        Matrix start(2, 2);
        start.X[0][0] = start.X[0][1] = start.X[1][0] = 1;

        Matrix FIB = luy_thua(start, i);
        f[i] = FIB.X[0][1];
        f[i-1] = FIB.X[1][1];

        for (ll u = 1; u < n; u++) {
            f[u+i] = (f[u+i-1]+f[u+i-2])%k;
        }

        for (ll mask = 1; mask <= (ll)(1<<n)-1; mask++) {
            q.clear();  
            ll tmp = mask;
            ll sum = 0;
            ll u = 0;

            while (tmp) {
                if (tmp & 1) {
                    sum += f[u+i];
                    q.push_back(u+i);
                }

                tmp >>= 1;
                u++;
            }

            if (sum % k == 0 && sum >= k) {
                cout << q.size() << ' ';

                for (auto const &v : q) {
                    cout << v << ' ';
                }

                cout << el;
                return;
            }
        }

        cout << 0 << el;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("FIBSEQ.inp", "r", stdin);
    freopen("FIBSEQ.out", "w", stdout);
    #endif

    cin >> T;

    while (T--) {
        cin >> n >> i >> k;
        if (n <= 20) {
            sub1::driver();
        } else {
            AC::driver();
        }
    }
    
    return 0;
}
