#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 2e5+1;

int n, q;
ll arr[MAXN], f[MAXN];
ll tree[4*MAXN];

int get_f(int num) {
    while (num % 2 == 0) {
        num /= 2;
    }

    return num;
}

struct SegmentTree {
    void build(int l=1, int r=n, int idx=1) {
        if (l > r) return;
        if (l == r) {
            tree[idx] = arr[l] + arr[f[l]];
            return;
        }

        int mid = (l+r)/2;
        build(l, mid, 2*idx);
        build(mid+1, r, 2*idx+1);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    int query(int ql, int qr, int l=1, int r=n, int idx=1) {
        if (l > r || ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[idx];

        int mid = (l+r)/2;
        return query(ql, qr, l, mid, 2*idx) + query(ql, qr, mid+1, r, 2*idx+1);
    }

    void update(int pos, int l=1, int r=n, int idx=1) {
        if (pos < l || r < pos) return;
        if (l == r) {
            tree[idx] = arr[l] + arr[f[l]];
            return;
        }

        int mid = (l+r)/2;
        update(pos, l, mid, 2*idx);
        update(pos, mid+1, r, 2*idx+1);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> arr[i];
        f[i] = get_f(i);
    }

    SegmentTree st;
    st.build();

    while (q--) {
        int k;
        cin >> k;

        if (k == 1) {
            int i, c;
            cin >> i >> c;
            arr[i] = c;

            if (!(i & 1)) {
                st.update(i);
            } else {
                while (i <= n) {
                    st.update(i);
                    i *= 2;
                }
            }
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << '\n';
        }
    }

    return 0;
}