#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct re {
    int x, y, u, v, c;
};

int r, c, Q;
vector<vector<int>> board;
int min_res = INT_MAX;
vector<re> truy_van;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> r >> c;
    board.assign(r+1, vector<int>(c+1, 0));

    FOR(i, 1, r) {
        FOR(j, 1, c) {
            cin >> board[r][c];
        }
    }

    cin >> Q;
    while (Q--) {
        re tmp;
        cin >> tmp.x >> tmp.y >> tmp.u >> tmp.v >> tmp.c;
        truy_van.push_back(tmp);

        FOR(i, tmp.x, tmp.u) {
            FOR(j, tmp.y, tmp.v) {
                board[i][j] += tmp.c;
            }
        }
    }

    for (auto const &t : truy_van) {
        vector<vector<int>> clone_board(board);
        int max_ans = INT_MIN;

        FOR(i, t.x, t.u) {
            FOR(j, t.y, t.v) {
                clone_board[i][j] -= t.c;
            }
        }
        
        FOR(i, 1, r) {
            FOR(j, 1, c) {
                max_ans = max(max_ans, clone_board[i][j]);
            }
        }

        min_res = min(min_res, max_ans);
    }

    cout << min_res;
    return 0;
}