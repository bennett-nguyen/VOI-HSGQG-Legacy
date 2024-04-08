#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

struct re {
    int x, t, y1, y2;
};

int n;
vector<re> point;
int tree[4*MAXN];

struct SegmentTree {
    void update(int pos, int val, int l, int r, int idx) {
        if (l > r || pos < l || pos > r) return;
        if (l == r) {
            tree[idx] += val;
            return;
        }

        int mid = (l+r)/2;
        update(pos, val, l, mid, 2*idx);
        update(pos, val, mid+1, r, 2*idx+1);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    int query(int ql, int qr, int l, int r, int idx) {
        if (l > r || ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[idx];

        int mid = (l+r)/2;
        return query(ql, qr, l, mid, 2*idx) + query(ql, qr, mid+1, r, 2*idx+1);
    }
};

int res = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    FOR(i, 1, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (y1 == y2) {
            point.push_back({x1, 1, y1, 0}); // begin
            point.push_back({x2, 3, y1, 0}); // end
        } else if (x1 == x2) {
            point.push_back({x1, 2, y1, y2}); // vertical line
        }
    }

    SegmentTree st;
    sort(point.begin(), point.end(), [](const re &a, const re &b) -> bool { return (a.x < b.x) || (a.x == b.x && a.t < b.t); });

    for (auto const &p : point) {
        if (p.t == 1) {
            st.update(p.y1, 1, 1, n, 1);
        } else if (p.t == 3) {
            st.update(p.y1, -1, 1, n, 1);
        } else if (p.t == 2) {
            res += st.query(p.y1, p.y2, 1, n, 1);
        }
    }

    cout << res;
    return 0;
}