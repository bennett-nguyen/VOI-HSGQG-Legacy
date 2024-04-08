#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n, k;
vector<int> a, tree;

struct SegmentTree {
    void build(int l=1, int r=n, int idx=1) {
        if (l == r) tree[idx] = a[l];
        else if (l < r) {
            int mid = (l+r)/2;
            build(l, mid, 2*idx);
            build(mid+1, r, 2*idx+1);
            tree[idx] = min(tree[2*idx], tree[2*idx+1]);
        }
    }

    int query(int ql, int qr, int l=1, int r=n, int idx=1) {
        if (l > r || l > qr || ql > r) return INT_MAX;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l+r)/2;

        return min(query(ql, qr, l, mid, 2*idx), query(ql, qr, mid+1, r, 2*idx+1));
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
    freopen("MINIMUM.inp", "r", stdin);
    freopen("MINIMUM.out", "w", stdout);

    cin >> n >> k;
    a.assign(n+1, 0);
    tree.assign(4*n+1, 0);

    FOR(i, 1, n) cin >> a[i];

    SegmentTree st;
    st.build();

    FOR(i, 1, n-k+1) {
        cout << st.query(i, i+k-1) << el;
    }

    return 0;
}