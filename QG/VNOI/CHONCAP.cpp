#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct re {
    int sum = 0, i, j;
};

const int maxn = 2001;

int n, m = 0, d;
int a[maxn];

namespace sub12 {
    vector<re> cap;

    void driver() {
        FOR(i, 1, n) {
            FOR(j, i+1, n) {
                re tmp;
                tmp.sum = a[i]+a[j];
                tmp.i = i;
                tmp.j = j;
                cap.push_back(tmp);
            }
        }

        sort(cap.begin(), cap.end(), [](const re &u, const re &v) -> bool {
            return (u.sum < v.sum) ||
                (u.sum == v.sum && u.i < v.i) ||
                (u.sum == v.sum && u.i == v.i && u.j > v.j);
        });

        FOR(i, 0, (int)cap.size()-1) {
            if (i+1 == cap.size()) break;

            int j = i+1;
            if (cap[i].sum == cap[j].sum) {
                
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i];

    if (n <= 200 && d == 0) {
        sub12::driver();
    }

    

    return 0;
}