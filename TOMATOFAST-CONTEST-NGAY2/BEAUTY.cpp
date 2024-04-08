#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 3e5+1;

int n;
ll psum[maxn];
ll max_res = LLONG_MIN;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    FOR(i, 1, n) {
        int tmp;
        cin >> tmp;
        psum[i] = psum[i-1]+tmp;
    }

    for (int k = 4; k <= n; k += 2) {
        for (int i = 1; i+k-1 <= n; i++) {
            max_res = max(max_res, psum[i+k-1]-psum[i-1]);
        }
    }

    cout << max_res;
    return 0;
}