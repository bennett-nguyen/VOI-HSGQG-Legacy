#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1001;

int N, r_pos, c_pos, S;
char board[MAXN][MAXN];
int f[MAXN][MAXN][4];

const pair<int, int> directions[4] = {
    make_pair(-1, 0),
    make_pair(0, -1),
    make_pair(1, 0),
    make_pair(0, 1)
};

namespace sub1 {
    bool check(int r, int c) {
        return (1 <= r && r <= N && 1 <= c && c <= N);
    }

    void driver() {
        int k = 0;

        do {
            pair<int, int> direction = directions[k];
            int r_pos_next = r_pos + direction.first;
            int c_pos_next = c_pos + direction.second;

            if (!check(r_pos_next, c_pos_next)) {
                S--;
                r_pos = r_pos_next;
                c_pos = c_pos_next;
                continue;
            }
    
            if (board[r_pos_next][c_pos_next] == '#') {
                k++;
                k %= 4;
            } else {
                S--;
                r_pos = r_pos_next;
                c_pos = c_pos_next;
            }

        } while (S);

        cout << c_pos << ' ' << r_pos;
    }
}

namespace AC {
    int cnt = 0, k = 0;

    void driver() {
        if (c_pos < 1 || c_pos > N || r_pos < 1 || r_pos-S > N) {
            cout << r_pos-S << ' ' << c_pos;
        } else if (r_pos > N && board[N][c_pos] == '#') {
            cout << N+1 << ' ' << c_pos-(S-(r_pos-N+1));
        } else {
            while (r_pos >= 1 && r_pos <= N && c_pos >= 1 && c_pos <= N && S) {
                S--;
                cnt++;

                if (f[r_pos][c_pos][k] == 0) f[r_pos][c_pos][k] = cnt;
                else S %= cnt - f[r_pos][c_pos][k];

                int new_r_pos = r_pos + directions[k].first;
                int new_c_pos = c_pos + directions[k].second;
                while (board[new_r_pos][new_c_pos] == '#') k = (k+1)%4;
                r_pos = new_r_pos;
                c_pos = new_c_pos;
            }

            cout << c_pos + S*directions[k].second << ' ' << r_pos + S*directions[k].first;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> N >> c_pos >> r_pos >> S;

    FOR(i, 1, N) {
        FOR(j, 1, N) {
            cin >> board[i][j];
        }
    }

    sub1::driver();
    return 0;
}