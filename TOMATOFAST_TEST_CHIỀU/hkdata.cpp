#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

int n, q;
int arr[maxn];

namespace sub1 {
    int psum[21];

    void driver() {
        while (q--) {
            int max_res = INT_MIN;
            int u, v, c;
            cin >> u >> v >> c;

            FOR(i, 1, n) {
                psum[i] = 0;
                if (u <= i && i <= v) {
                    psum[i] = psum[i-1]+arr[i]+c;
                } else {
                    psum[i] = psum[i-1]+arr[i];
                }
            }

            FOR(i, 1, n) {
                FOR(j, 1, i) {
                    max_res = max(max_res, abs(psum[i]-psum[j-1]));
                }
            }

            cout << max_res << el;
        }
    }
}

namespace sub2 {
    int psum[5001];
    pair<int, int> truy_vet;

    void driver() {
        while (q--) {
            int max_res = INT_MIN;
            int u, v, c;
            cin >> u >> v >> c;

            FOR(right_i, 1, n) {
                FOR(left_i, 1, right_i) {
                    if (right_i < u || left_i > v) {
                        max_res = max(max_res, abs(psum[right_i]-psum[left_i-1]));
                    } else if (left_i <= u && v <= right_i) {
                        max_res = max(max_res, abs((psum[right_i]-psum[left_i-1])+(v-u+1)*c));
                    } else if (left_i < u && u <= right_i && right_i <= v) {
                        max_res = max(max_res, abs((psum[right_i]-psum[left_i-1])+(right_i-u+1)*c));
                    } else if (right_i > v && u <= left_i && left_i <= v) {
                        max_res = max(max_res, abs((psum[right_i]-psum[left_i-1])+(v-left_i+1)*c));
                    } else if (u <= left_i && right_i <= v) {
                        max_res = max(max_res, abs(psum[right_i]-psum[left_i-1]+(right_i-left_i+1)*c));
                    }
                }
            }

            cout << max_res << el;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("hkdata.inp", "r", stdin);
    freopen("hkdata.out", "w", stdout);
    
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> arr[i];
        sub2::psum[i] = sub2::psum[i-1]+arr[i];
    }

    if (n <= 20 && q <= 20) {
        sub1::driver();
    } else {
        sub2::driver();
    }
    return 0;
}