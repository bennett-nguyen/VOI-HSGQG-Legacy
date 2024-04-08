#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXRC = 1e4+1;

int theta;
int rows, columns;
vector<int> arr[MAXRC];

namespace sub1 {
    void run() {

    }
}

namespace sub2 {
    const int MAXT = 1e4+1;
    vector<int> tree;

    struct SegmentTree {
        void build_tree(int l=1, int r=columns, int idx=1) {
            if (l == r) {
                tree[idx] = arr[1][l];
                return;
            }
            int mid = (l+r)/2;

            build_tree(l, mid, 2*idx);
            build_tree(mid+1, r, 2*idx+1);

            tree[idx] = __gcd(tree[2*idx], tree[2*idx+1]);
        }

        int query(int ql, int qr, int l=1, int r=columns, int idx=1) {
            if (l > r || qr < l || ql > r) return 0;
            if (ql <= l && r <= qr) return tree[idx];

            int mid = (l+r)/2;
            return __gcd(query(ql, qr, l, mid, 2*idx), query(ql, qr, mid+1, r, 2*idx+1));
        }
    };

    SegmentTree st;

    void run() {
        tree.assign(4*columns+1, 0);
        st.build_tree();

        int max_res = 0;

        FOR(i, 1, columns) {
            FOR(j, 1, i) {
                if (st.query(j, i) == 1) continue;
                max_res = max(max_res, i-j+1);
            }
        }

        cout << max_res;
    }
}

namespace sub3 {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    map<pair<int, int>, bool> visited;
    queue<pair<int, int>> q;

    bool check(pair<int, int> p, int t) {
        return (1 <= p.first && p.first <= rows && 1 <= p.second && p.second <= columns && arr[p.first][p.second] == t && !visited[p]);
    }

    int BFS(pair<int, int> start) {
        q.push(start);
        visited[start] = true;
        int d = 1;

        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();

            FOR(k, 0, 3) {
                pair<int, int> v = make_pair(u.first+dx[k], u.second+dy[k]);
                if (!check(v, arr[start.first][start.second])) continue;
                d++;
                visited[v] = true;
                q.push(v);
            }
        }

        return d;
    }

    int res = 0, ans; 
    void run() {
        FOR(i, 1, rows) {
            FOR(j, 1, columns) {
                if (visited[make_pair(i, j)]) continue;
                ans = BFS(make_pair(i, j));
                res = max(res, ans);
            }
        }

        cout << res;
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("numtable.inp", "r", stdin);
    freopen("numtable.out", "w", stdout);
    #endif

    cin >> theta;
    cin >> rows >> columns;

    FOR(i, 1, rows) {
        arr[i].assign(columns+1, 0);
        FOR(j, 1, columns) {
            cin >> arr[i][j];
        }
    }

    switch (theta) {
        case 1:
            sub1::run();
            break;
        case 2:
            sub2::run();
            break;
        case 3:
            sub3::run();
            break;
        default:
            cout << -1;
    }

    return 0;
}