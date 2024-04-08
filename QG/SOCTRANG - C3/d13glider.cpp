#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

struct re {
    int h, p;
};

int n;
re arr[MAXN];

namespace AC {
    void run() {
        sort(arr+1, arr+1+n, [](const re &a, const re &b) -> bool { return a.h < b.h; });

    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;

    FOR(i, 1, n) {
        cin >> arr[i].h >> arr[i].p;
    }

    AC::run();
    return 0;
}