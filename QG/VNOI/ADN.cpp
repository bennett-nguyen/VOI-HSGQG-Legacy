#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

string s;

namespace sub1 {
    void driver() {

    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("ADN.INP", "r", stdin);
    freopen("ADN.OUT", "w", stdout);
    #endif

    cin >> s;
    
    if (s.size() <= 10) {
        sub1::driver();
    }

    return 0;
}
