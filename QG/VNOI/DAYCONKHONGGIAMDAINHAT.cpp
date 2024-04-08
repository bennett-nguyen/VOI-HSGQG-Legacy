#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

int n, p, res = INT_MIN, m = 0;
int arr[MAXN], psum[MAXN], val[MAXN];

int bin_search(int x) {
    int l = 1, r = m, ans = 0;

    while (l <= r) {
        int mid = (l+r)/2;

        if (psum[x] - psum[val[mid]] < p) {
            l = mid+1;
        } else {
            ans = mid;
            r = mid-1;
        }
    }

    return ans;
}

void sub1() {
    FOR(i, 1, n) {
        FOR(j, 1, i) {
            if (psum[i] - psum[j-1] >= p) {
                res = max(res, i-j+1);
            }
        }
    }

    if (res == INT_MIN) cout << -1;
    else cout << res;
}

void sub2() {
    int res = INT_MIN;

    FOR(i, 1, n) {
        if (psum[i] >= p) res = i;
        int j = bin_search(i);
        if (j == 0) continue;
        while (j <= i) {
            if (val[j] <= i) {
                if (psum[i] - psum[val[j]] >= p) {
                    res = max(res, i-val[j]);
                }
            }

            j++;
        }
    }

    if (res == INT_MIN) cout << -1;
    else cout << res;
}

// first: sum
// second: idx

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> p;
    int min_val = INT_MAX;
    FOR(i, 1, n) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i-1];
        
        if (psum[i] >= min_val) {
            m++;
            val[m] = i;
            min_val = psum[i];
        }
    }

    if (n <= 2000) sub1();
    else sub2();
    return 0;
}