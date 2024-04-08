#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define forw(i, l, r) for (int i = l; i <= r; i++)
#define fodd(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

int n;
int arr[maxn];

namespace sub1 {
    int psum[11];
    int cnt = 0;

    bool is_fib(ll sum) {
        int f_1 = 0, f_2 = 1, f_n;

        do {
            f_n = f_1 + f_2;
            if (f_n == sum) return true;
            f_1 = f_2;
            f_2 = f_n;
        } while (f_n < sum);

        return false;
    }

    void DFS(int i) {
        if (i > n) {
            cnt++;
            return;
        }

        forw(k, i, n) {
            if (is_fib(psum[k]-psum[i-1])) {
                DFS(k+1);
            }
        }
    }

    void driver() {
        DFS(1);
        cout << cnt;
    }
}

namespace sub2 {
    const int max = 1e3+1;
    const int MOD = 1e9+7;
    int dp[max];

    bool is_fib(ll sum) {
        ll f_1 = 0, f_2 = 1, f_n;

        do {
            f_n = f_1 + f_2;
            if (f_n == sum) return true;
            f_1 = f_2;
            f_2 = f_n;
        } while (sum > f_n);

        return false;
    }

    void driver() {
        dp[0] = 1;

        forw(i, 1, n) {
            ll sum = 0;
            fodd(j, i, 1) {
                sum += arr[j];
                if (is_fib(sum)) {
                    dp[i] += dp[j-1];
                    dp[i] %= MOD;
                }
            }
        }

        cout << dp[n];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    forw(i, 1, n) {
        cin >> arr[i];
        sub1::psum[i] = sub1::psum[i-1] + arr[i];
    }

    sub2::driver();
    return 0;
}