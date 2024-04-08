#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 501;
const pair<int, int> direction1[3] = {
    make_pair(1, 1),
    make_pair(0, 1),
    make_pair(1, 0)
};

const pair<int, int> direction2[3] = {
    make_pair(1, -1),
    make_pair(0, -1),
    make_pair(1, 0)
};


int n, k;
int d1[maxn][maxn], d2[maxn][maxn];
bool visited[maxn][maxn];
bool blocked[maxn][maxn];

bool check(pair<int, int> current) {
    return (1 <= current.first && current.first <= n && 1 <= current.second && current.second <= n && !visited[current.first][current.second] && !blocked[current.first][current.second]);
}

void BFS1() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    d1[1][1] = 0;
    visited[1][1] = true;

    while (q.size()) {
        pair<int, int> current = q.front();
        q.pop();

        for (auto const &direction : direction1) {
            pair<int, int> child = make_pair(current.first+direction.first, current.second+direction.second);
            if (!check(child)) continue;

            d1[child.first][child.second] = d1[current.first][current.second]+1;
            visited[child.first][child.second] = true;
            q.push(child);
        }
    }
}

void BFS2() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(1, n));
    d2[1][n] = 0;
    visited[1][n] = true;

    while (q.size()) {
        pair<int, int> current = q.front();
        q.pop();

        for (auto const &direction : direction2) {
            pair<int, int> child = make_pair(current.first+direction.first, current.second+direction.second);
            if (!check(child)) continue;

            d2[child.first][child.second] = d2[current.first][current.second]+1;
            visited[child.first][child.second] = true;
            q.push(child);
        }
    }
}

int min_ans = INT_MAX;


/*
0  1  2 -1  0 
1 -1 -1  3  4 
2  2  3  4 -1 
3 -1  3  4  5 
4  4  4  4  5

-1 -1 -1 -1  0 
-1 -1 -1  1  1 
 4  3  2  2 -1 
 4 -1  3  3 -1 
 5  4  4  4 -1 
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> k;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            d1[i][j] = d2[i][j] = -1;
        }
    }

    while (k--) {
        int u, v;
        cin >> u >> v;
        blocked[u][v] = true;
    }

    BFS1();
    BFS2();

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if ((i == 1 && (j == 1 || j == n)) || d1[i][j] == -1 || d2[i][j] == -1) continue;
            if (d1[i][j] == d2[i][j]) {
                min_ans = min(min_ans, d1[i][j]);
            }
        }
    }

    cout << min_ans;
    return 0;
}