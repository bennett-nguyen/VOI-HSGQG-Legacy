#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 2001;

int n, m;
vector<int> dsk[MAXN];
stack<int> st;
int low[MAXN], num[MAXN], color[MAXN], pt[MAXN];
int in[MAXN], out[MAXN];

int TIME = 0, LABEL = 0;
void tarjan(int u) {
    TIME++;
    st.push(u);
    low[u] = num[u] = TIME;
    color[u] = GRAY;

    for (auto const &v : dsk[u]) {
        if (color[v] == WHITE) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (color[v] == GRAY) {
            low[u] = min(low[u], num[v]);
            pt[u] = LABEL;
        }
    }

    if (low[u] == num[u]) {
        int x;
        LABEL++;
        
        do {
            x = st.top();
            st.pop();
            pt[x] = LABEL;
            color[x] = BLACK;
        } while (x != u);
    }
}

int source = 0, s_i = 0;
int sink = 0, t_i = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        dsk[x].push_back(y);
    }

    FOR(i, 1, n) {
        if (color[i] == WHITE) {
            tarjan(i);
        }
    }

    FOR(u, 1, n) {
        for (auto const v: dsk[u]) {
            if (pt[u] != pt[v] ) {
                in[pt[v]]++;
                out[pt[u]]++;
            }
        }
    }

    FOR(i, 1, LABEL) {
        if (!in[i]) {
            source++;
            s_i = i;
        }

        if (!out[i]) {
            sink++;
            t_i = i;
        }
    }

    if (source != 1 || sink != 1) {
        cout << "NO";
    } else {
        int s, t;
        cout << "YES" << '\n';
        FOR(i, 1, n) {
            if (pt[i] == s_i) {
                s = i;
                break;
            }
        }

        FOR(i, 1, n) {
            if (pt[i] == t_i) {
                t = i;
                break;
            }
        }

        cout << t << ' ' << s;
    }
    return 0;
}