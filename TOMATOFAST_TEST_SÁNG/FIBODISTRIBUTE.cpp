#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long unsigned
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;
const int MOD = 1e7+7;

int n, cnt = 0;
int arr[MAXN], psum[MAXN];
unordered_map<ll, bool> f;
vector<pair<int, int>> cau_hinh;

namespace sub1 {
    void DFS(int k=1) {
        if (k > n) {
            cnt++;
            for (auto const &i : cau_hinh) {
                cout << i.first << ' ' << i.second << el;
            }
            return;
        }

        FOR(i, k, n) {
            if (f[psum[i]-psum[k-1]]) {
                cau_hinh.push_back(make_pair(k, i));
                DFS(i+1);
                cau_hinh.pop_back();
            }
        }
    }

    void driver() {
        DFS(1);
        cout << cnt % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("FIBODISTRIBUTE.inp", "r", stdin);
    freopen("FIBODISTRIBUTE.out", "w", stdout);

    cin >> n;
    f[0] = f[1] = true;

    ll u = 1, v = 1;
    FOR(i, 2, 90) {
        ll x = u + v;
        f[x] = true;
        u = v;
        v = x;
    }

    FOR(i, 1, n) {
        cin >> arr[i];
        psum[i] = psum[i-1]+arr[i];
    }

    sub1::driver();
    return 0;
}