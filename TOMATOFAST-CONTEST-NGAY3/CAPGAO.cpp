#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long unsigned
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1, maxm = 21;

int m, n;
int w[maxm], a[maxn];

bool bin_search(int val) {
    int l = 1, r = m, mid;

    while (l <= r) {
        mid = (l+r)/2;

        if (w[mid] == val) {
            return true;
        } else if (w[mid] > val) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    return false;
}

int search_vi_tri(int val) {
    int l = 1, r = m, mid;
    int res = -1;

    while (l <= r) {
        mid = (l+r)/2;

        if (w[mid] > val) {
            r = mid-1;
        } else {
            res = mid;
            while (w[res] < val) res++;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> m >> n;
    FOR(i, 1, m) cin >> w[i];

    sort(w+1, w+1+n);
    // FOR(i, 1, n) {
    //     int tmp;
    //     cin >> tmp;

    //     if (bin_search(tmp)) {
    //         cout << 1;
    //         continue;
    //     }

    //     int j = lower_bound(w+1, w+1+n, tmp) - w;
    // }
    search_vi_tri(6);
    return 0;
}