#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 4e6+1;

int n, m;
int arr[MAXN], pos[MAXN], en[MAXN], co[MAXN];
int tree[MAXN];
vector<int> dsk[100001];

struct SegmentTree {

    void build(int l, int r, int idx) {
        if (l > r) return;
        if (l == r) {
            tree[idx] = arr[co[l]];
            return;
        }

        int mid = (l+r)/2;
        build(l, mid, 2*idx);
        build(mid+1, r, 2*idx+1);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    int query(int ql, int qr, int l, int r, int idx) {
        if (l > r || qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[idx];

        int mid = (l+r)/2;
        return query(ql, qr, l, mid, 2*idx) + query(ql, qr, mid+1, r, 2*idx+1);
    }

    void update(int pos, int val, int l, int r, int idx) {
        if (l > r || r < pos || pos < l) return;
        if (l == r) {
            tree[idx] = val;
            return;
        }

        int mid = (l+r)/2;
        update(pos, val, l, mid, 2*idx);
        update(pos, val, mid+1, r, 2*idx+1);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }
};

int TIME = 0;

void DFS(int u, int p) {
    ++TIME;
    pos[u] = TIME;
    co[TIME] = u;

    for (auto const &v : dsk[u]) {
        if (v == p) continue;
        DFS(v, u);
    }

    en[u] = TIME;
}

void sub1() {
    DFS(1, 0);
    SegmentTree st;
    st.build(1, n, 1);

    char c;
    int u, v;

    while (m--) {
        cin >> c >> u;
        if (c == 'Q') {
            cout << st.query(pos[u], en[u], 1, n, 1) << '\n';
        } else {
            cin >> v;
            st.update(pos[u], v, 1, n, 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    freopen("SCOMP.inp", "r", stdin);
    freopen("SCOMP.out", "w", stdout);
    
    cin >> n >> m;
    FOR(i, 1, n) cin >> arr[i];

    FOR(i, 1, n-1) {
        int x, y;
        cin >> x >> y;
        dsk[x].push_back(y);
        dsk[y].push_back(x);
    }

    sub1();
    return 0;
}