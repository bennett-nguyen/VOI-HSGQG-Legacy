#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXRC = 1001;

int r, c, k;
vector<vector<pair<int, int>>> ho;
char b[MAXRC][MAXRC];
bool visited[MAXRC][MAXRC];
pair<int, int> d[4] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

bool is_on_outer_edge(int i, int j) {
    return (i == 1 || i == r || j == 1 || j == c);
}

bool is_valid(int i, int j) {
    return (b[i][j] == '.' && 1 <= i && i <= r && 1 <= j && j <= c && !visited[i][j]);
}

void BFS(int i, int j) {
    queue<pair<int, int>> q;
    visited[i][j] = true;
    vector<pair<int, int>> kq;
    bool ok = false;
    if (is_on_outer_edge(i, j)) ok = true;
    q.push(make_pair(i, j));

    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        kq.push_back(u);

        FOR(k, 0, 3) {
            pair<int, int> dk = d[k];
            pair<int, int> v = make_pair(u.first+dk.first, u.second+dk.second);

            if (!is_valid(v.first, v.second)) continue;
            visited[v.first][v.second] = true;
            q.push(v);
            if (is_on_outer_edge(v.first, v.second)) ok = true;
        }
    }

    if (!ok) {
        ho.push_back(kq);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    #ifdef ONLINE_JUDGE
    freopen("hanoi.inp", "r", stdin);
    freopen("hanoi.out", "w", stdout);
    #endif

    cin >> r >> c >> k;
    FOR(i, 1, r) {
        FOR(j, 1, c) {
            cin >> b[i][j];
        }
    }

    FOR(i, 1, r) {
        FOR(j, 1, c) {
            if (b[i][j] == '.' && !visited[i][j]) BFS(i, j);
        }
    }

    sort(ho.begin(), ho.end(), [](const vector<pair<int, int>> &a, const vector<pair<int, int>> &b) -> bool { return a.size() < b.size(); });

    int cnt = ho.size();
    int i = 0, res = 0;

    if (cnt > k) {
        while (cnt > k && i < ho.size()) {
            res += ho[i].size();

            for (auto const &j : ho[i]) {
                b[j.first][j.second] = '#';
            }

            i++;
            cnt--;
        }
    } else if (k == 0) {
        while (i < ho.size()) {
            res += ho[i].size();

            for (auto const &j : ho[i]) {
                b[j.first][j.second] = '#';
            }

            i++;
        }
    }

    cout << res << '\n';
    FOR(i, 1, r) {
        FOR(j, 1, c) {
            cout << b[i][j];
        }
        cout << el;
    }

    return 0;
}