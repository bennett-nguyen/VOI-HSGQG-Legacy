#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct re {
    int x, y, p, q;
};

const int maxn = 1e5+1;

int n;
vector<re> v;
vector<int> dsk[maxn];

namespace sub1 {
    bool check() {
        return n <= 1e3;
    }

    void driver() {

    }
}

bool check(re h1, re h2) {
    if (h1.q < h2.y || h1.y > h2.q) return false;
    if (h1.p < h2.x || h1.x > h2.p) return false;
    return true;


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;

    FOR(i, 1, n) {
        re tmp;
        cin >> tmp.x >> tmp.y >> tmp.p >> tmp.q;
        v.push_back(tmp);
    }

    FOR(i, 0, v.size()-1) {
        FOR(j, 0, v.size()-1) {
            if (i == j) continue;
            if (!check(v[i], v[j])) continue;
            cout << i+1 << ' ' << j+1 << el;
        }
    }
    
    return 0;
}