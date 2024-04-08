#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

int n, Q;
int arr[MAXN];

struct SegmentTree {
    int tree[4*MAXN];

    void build(int l=1, int r=n, int idx=1) {
        if (l == r) tree[idx] = arr[l];
        else {
            int mid = (l+r)/2;
            build(l, mid, 2*idx);
            build(mid+1, r, 2*idx+1);
            tree[idx] = tree[2*idx] + tree[2*idx+1];
        }
    }

    int query(int ql, int qr, int l=1, int r=n, int idx=1) {
        if (l > r || qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[idx];

        int mid = (l+r)/2;
        return query(ql, qr, l, mid, 2*idx) + query(ql, qr, mid+1, r, 2*idx+1);
    }

    void update(int pos, int val, int l=1, int r=n, int idx=1) {
        if (l == r) {
            tree[idx] += val;
        } else {
            int mid = (l+r)/2;

            if (pos <= mid) {
                update(pos, val, l, mid, 2*idx);
            } else {
                update(pos, val, mid+1, r, 2*idx+1);
            }

            tree[idx] = tree[2*idx] + tree[2*idx+1];
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> n >> Q;
    FOR(i, 1, n) cin >> arr[i];

    SegmentTree st;
    st.build();

    while (Q--) {
        int c, u, v;
        cin >> c >> u >> v;

        if (c == 2) {
            cout << st.query(u, v) << ' ';
        } else {
            st.update(u, v);
        }
    }

    return 0;
}