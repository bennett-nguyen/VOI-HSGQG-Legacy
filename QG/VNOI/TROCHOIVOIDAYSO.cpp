#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

int n;
int b[MAXN];
int c[MAXN];
multiset<int> d;

void sub1() {
    int res = INT_MAX;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            res = min(res, abs(b[i]+c[j]));
        }
    }

    cout << res;
}

int bin_search(int x) {
    int l = -1, r = 1e9, ans = -1;

    while (l <= r) {
        int mid = (l+r)/2;
        
        if (d.find(mid-x) != d.end() || d.find(-mid-x) != d.end()) {
            l = mid + 1;
            ans = abs(mid+x);
            cout << ans << ' ' << "x: " << x << ' ' << mid << endl;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

void sub2() {
    int res = INT_MAX;

    FOR(i, 1, n) {
        int j = bin_search(b[i]);
        if (j != -1) {
            res = min(res, j);
        }
    }

    cout << res;
}   

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, n) {
        cin >> c[i];
        d.insert(c[i]);
    }
    
    if (n <= 1000) sub1();
    else sub2();
    return 0;
}