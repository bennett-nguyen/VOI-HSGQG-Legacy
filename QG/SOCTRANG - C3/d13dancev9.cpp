#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1001;

int n, k;
int arr[MAXN];
unordered_map<int, bool> chosen;

namespace sub1 {
    int res = 0;
    pair<int, int> pdifference[MAXN];

    // p[i] = a[i+1] - a[i]
    void run() {
        sort(arr+1, arr+1+n);
        
        FOR(i, 2, n) {
            pdifference[i-1].first = arr[i] - arr[i-1];
            pdifference[i-1].second = i-1;
        }
        
        sort(pdifference+1, pdifference+n, [](const pair<int, int> &a, const pair<int, int> &b) -> bool {return (a.first < b.first) || (a.first == b.first) && a.second < b.second; });

        int cnt = 0;
        FOR(i, 1, n-1) {
            if (cnt >= k) break;
            if (!chosen[pdifference[i].second] && !chosen[pdifference[i].second-1] && !chosen[pdifference[i].second+1]) {
                res += pdifference[i].first;
                chosen[pdifference[i].second] = true;
                cnt++;
            }
        }

        cout << res;
    }
}

namespace FULL_AC {
    int F[MAXN][MAXN];
    
    ll QHD(int i, int k) {
        if (F[i][k] > -1) return F[i][k];
        if (k == 0) return 0;

        ll best = INT_MAX;

        if (i >= 2) {
            best = QHD(i-2, k-1) + abs(arr[i] - arr[i-1]);
        }
        if ((i-1) >= 2*k) {
            best = min(best, QHD(i-1, k));
        }

        return F[i][k] = best;
    }

    void run() {
        sort(arr+1, arr+1+n);
        memset(F, -1, sizeof(F));
        cout << QHD(n, k);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n >> k;
    FOR(i, 1, n) cin >> arr[i];

    // if (n <= 10) {
    // sub1::run();
    // }
    
    FULL_AC::run();
    return 0;
}