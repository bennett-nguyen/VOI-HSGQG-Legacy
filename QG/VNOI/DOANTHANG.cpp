#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

struct re {
    int i, j;
};

int len_re(const re u) {
    return u.j - u.i;
}

int getbit(int i, int k) {
    return (i >> (k-1)) & 1;
}

bool co_phai_la_con(re cha, re con) {
    return (cha.i <= con.i) && (con.j <= cha.j);
}

int n, res = -1;
re a[MAXN];
int f[MAXN];

void sub1() {
    sort(a+1, a+1+n, [](const re &a, const re &b) -> bool { return len_re(a) < len_re(b) || (len_re(a) == len_re(b) && a.i < b.i); });

    FOR(i, 1, (1<<n)-1) {
        int cnt = 0;
        bool chua_co_cha = true;
        re cha, con;

        FOR(k, 1, n) {
            if (getbit(i, k) != 1) continue;
            cha = a[k];

            if (chua_co_cha) {
                cnt++;
                con = cha;
                chua_co_cha = false;
                continue;
            }

            if (co_phai_la_con(cha, con)) {
                cnt++;
                con = cha;
            }
        } 

        res = max(res, cnt);
    }

    cout << res;
}

void sub2() {
    sort(a+1, a+1+n, [](const re &a, const re &b) -> bool { return a.j < b.j || (a.j == b.j && a.i > b.i); });

    int res = 1;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        int l = 1, r = res;

        while (l <= r) {
            int m = (l + r) / 2;

            if (co_phai_la_con(a[i], a[f[m]])) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        f[l] = i;
        res = max(res, l);
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
    freopen("doanthang.inp", "r", stdin);
    freopen("doanthang.out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i].i >> a[i].j;
    }

    if (n <= 20) sub1();
    else sub2();
    // sub2();
    return 0;
}