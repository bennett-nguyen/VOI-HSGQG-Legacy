#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct re {
    ll a, b;
};

int n;
vector<re> v;

int prev_val_sub1 = -1, prev_val_sub2 = -1;
bool is_sub1 = true, is_sub2 = true;

namespace sub1 {
    void driver() {
        sort(v.begin(), v.end(), [](const re &a, const re &b) -> bool {
            return a.b < b.b;
        });

        int start_val = min(v[0].b, v[0].a);
        cout << start_val << el;
        FOR(i, 1, v.size()-1) {
            start_val += min(v[i].b, v[i].a);
            cout << start_val << el;
        }
    }
}

namespace sub2 {
    void driver() {

    }
}

namespace AC {
    void driver() {
        
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n;
    FOR(i, 1, n) {
        re tmp;
        cin >> tmp.a >> tmp.b;

        if (prev_val_sub1 == -1) {
            prev_val_sub1 = tmp.a;
        } else {
            if (is_sub1 && tmp.a != prev_val_sub1) {
                is_sub1 = false;
            }
        }

        if (prev_val_sub2 == -1) {
            prev_val_sub2 = tmp.b;
        } else {
            if (is_sub1 && tmp.b != prev_val_sub2) {
                is_sub2 = false;
            }
        }

        v.push_back(tmp);
    }

    // if (is_sub1) {
        sub1::driver();
    // } else if (is_sub2) {
    //     sub2::driver();
    // } else {
    //     AC::driver();
    // }

    return 0;
}