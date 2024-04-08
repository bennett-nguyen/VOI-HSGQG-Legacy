#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1001;

int n;
int arr[maxn], dp[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    dp[1] = 1;

    cin >> arr[1];
    FOR(i, 2, n) {
        dp[i] = 1;
        cin >> arr[i];

        FOR(j, 1, i-1) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    // FOR(i, 1, n) cout << dp[i] << ' ';
    cout << *max_element(dp+1, dp+1+n);
    return 0;
}