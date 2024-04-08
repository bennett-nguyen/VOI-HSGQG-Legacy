#include <bits/stdc++.h>
using namespace std;

#define el endl
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int k;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("a.inp", "r", stdin);
    // #endif

    // #ifdef ONLINE_JUDGE
    freopen("easy.inp", "r", stdin);
    freopen("easy.out", "w", stdout);
    // #endif
    
    cin >> k;
    while (getline(cin >> ws, s)) {
        if (s.size() > k) {
            cout << s[0] << s.size()-2 << s[s.size()-1] << ' ';
        } else {
            cout << s << ' ';
        }
    }

    return 0;
}