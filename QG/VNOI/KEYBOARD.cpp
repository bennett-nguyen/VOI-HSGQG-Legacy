#include <bits/stdc++.h>
#include "../lib/bit.hpp"
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n, m;
map<char, int> mp;
map<char, bool> fre;
vector<map<char, int>> cau_hinh;

string s;

void de_quy(int i = 1) {
    if (i > m) return;
    for (char c = 'a'; c <= 'a'+m-1; c++) {
        if (fre[c]) continue;

        fre[c] = true;
        mp[c] = i;

        if (i == m) cau_hinh.push_back(mp);
        else de_quy(i+1);

        fre[c] = false;
    }
}

void sub1() {
    s = ' ' + s;

    de_quy();
    for (auto &keyboard : cau_hinh) {
        int ans = 0;

        FOR(i, 2, n) {
            ans += abs(keyboard[s[i-1]] - keyboard[s[i]]);
        }

        res = min(ans, res);
    }

    cout << res;
}

void sub2() {

}

int res = INT_MAX;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> n >> m;
    getline(cin >> ws, s);
    
    if (m <= 5) sub1();
    else sub2();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 1e5 + 5;
// const int MAXM = 20 + 5;

// int n, m;
// string s;
// int pos[MAXM];
// int dp[1 << MAXM];

// // Độ chậm của một hoán vị
// int slow(int mask) {
//     int last = -1, res = 0;
//     for (int i = 0; i < m; ++i) {
//         if (mask & (1 << i)) {
//             if (last != -1) {
//                 res += abs(pos[i] - pos[last]);
//             }
//             last = i;
//         }
//     }
//     return res;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     cin >> n >> m >> s;
//     for (int i = 0; i < m; ++i) {
//         char c;
//         cin >> c;
//         pos[c - 'a'] = i;
//     }

//     memset(dp, 0x3f, sizeof(dp));
//     dp[0] = 0;

//     // Tìm tất cả các hoán vị của 𝑚 chữ cái Latin đầu tiên
//     for (int mask = 0; mask < (1 << m); ++mask) {
//         dp[mask] = slow(mask);
//     }

//     // Tìm độ chậm nhỏ nhất
//     for (int mask = 0; mask < (1 << m); ++mask) {
//         for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
//             dp[mask] = min(dp[mask], dp[submask] + dp[mask ^ submask]);
//         }
//     }

//     cout << dp[(1 << m) - 1] << '\n';

//     return 0;
// }
