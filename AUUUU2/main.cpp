#include <bits/stdc++.h>
using namespace std;

#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define ll long long
#define el '\n'

vector<pair<int, int>> directions = {
    make_pair(0, 1), // right
    make_pair(1, -1), // bottomleft
    make_pair(1, 0), // down
    make_pair(-1, 1) // topright
};

// 4 1 -> 3 2 -> 2 3

int n, q;
map<pair<int, int>, int> mp;

bool is_valid(int i, int j) {
    return (1 <= i && i <= n && 1 <= j && j <= n);
}

int main() {
    freopen("a.inp", "r", stdin);
    freopen("b.out", "w", stdout);
    int k = 3;
    int val = 1;
    cin >> n >> q;

    int r = 1, c = 1;
    mp[make_pair(1, 1)] = val;
    
    while (r*c != n*2) {
        int new_r = r + directions[k].first;
        int new_c = c + directions[k].second;

        if (!is_valid(new_r, new_c)) {
            k = (k+1) % 4;
            continue;
        }

        val++;
        r = new_r;
        c = new_c;
        mp[make_pair(r, c)] = val;

        cout << r << ' ' << c << ' ' << val << el;
    }
    
    while (q--) {
        pair<int, int> query;
        cin >> query.first >> query.second;
        cout << mp[query] << el;
    }

    return 0;
}