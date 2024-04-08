#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 2001;

int T, n;

// first: phan tu, second: tong cong don
vector<pair<int, int>> v;
int dp[maxn][maxn];

int DFS(int i, int j) {
    if (i == j || i > j || (v[j].second - v[i-1].second % 2)) return dp[i][j] = 0;
    if (i+1 == j) {
        return dp[i][j] = (v[i].first == v[j].first);
    }

    if (dp[i][j]) return dp[i][j];

    FOR(mid, i, j) {
        if (v[mid].second-v[i-1].second != v[j].second-v[mid].second) {
            continue;
        }

        dp[i][j] = max({dp[i][j], DFS(i, mid)+1, DFS(mid+1, j)+1});
    }

    return dp[i][j];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("seq.inp", "r", stdin);
    // freopen("seq.out", "w", stdout);
    freopen("a.inp", "r", stdin);

    cin >> T;

    while (T--) {
        cin >> n;
        v.clear();
        v.push_back(make_pair(0, 0));

        FOR(i, 1, n) {
            pair<int, int> tmp;
            cin >> tmp.first;
            tmp.second = v[i-1].second + tmp.first;
            v.push_back(tmp);
        }

        DFS(1, n);

        FOR(i, 1, n) {
            FOR(j, i+1, n) {
                cout << i << ' ' << j << ": " << dp[i][j] << el; 
            }
        }
    }

    return 0;
}