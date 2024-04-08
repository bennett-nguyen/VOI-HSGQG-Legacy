#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxc = 5e5+1;

int rows, columns;
int h[maxc], yellow_tree[4*maxc], green_tree[4*maxc];

struct SegmentTree {
    void build_yellow(int l=1, int r=columns, int idx=1) {
        if (l == r) yellow_tree[idx] = h[l];
        else if (l < r) {
            int mid = (l+r)/2;
            build_yellow(l, mid, 2*idx);
            build_yellow(mid+1, r, 2*idx+1);

            yellow_tree[idx] = min(yellow_tree[2*idx], yellow_tree[2*idx+1]);
        }
    }

    void build_green(int l=1, int r=columns, int idx=1) {
        if (l == r) green_tree[idx] = rows-h[l];
        else if (l < r) {
            int mid = (l+r)/2;
            build_green(l, mid, 2*idx);
            build_green(mid+1, r, 2*idx+1);

            green_tree[idx] = min(green_tree[2*idx], green_tree[2*idx+1]);
        }
    }

    int query_yellow(int ql, int qr, int l=1, int r=columns, int idx=1) {
        if (l > r || l > qr || ql > r) return INT_MAX;
        if (ql <= l && r <= qr) return yellow_tree[idx];
        int mid = (l+r)/2;

        return min(query_yellow(ql, qr, l, mid, 2*idx), query_yellow(ql, qr, mid+1, r, 2*idx+1));
    }

    int query_green(int ql, int qr, int l=1, int r=columns, int idx=1) {
        if (l > r || l > qr || ql > r) return INT_MAX;
        if (ql <= l && r <= qr) return green_tree[idx];
        int mid = (l+r)/2;

        return min(query_green(ql, qr, l, mid, 2*idx), query_green(ql, qr, mid+1, r, 2*idx+1));
    }
};

ll area = 1;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("a.inp", "r", stdin);
    // #else
    freopen("RECT.inp", "r", stdin);
    freopen("RECT.out", "w", stdout);
    // #endif

    cin >> rows >> columns;

    FOR(i, 1, columns) cin >> h[i];
    SegmentTree yellow, green;

    yellow.build_yellow();
    green.build_green();

    FOR(i, 1, columns) {
        FOR(j, 1, i) {
            ll yellow_height = yellow.query_yellow(j, i);
            ll green_height = green.query_green(j, i);
            area = max({area, yellow_height*(i-j+1), green_height*(i-j+1)});
        }
    }

    cout << area;
    return 0;
}