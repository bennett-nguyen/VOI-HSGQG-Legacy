#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

int n, m, to_tien;
bool visited[MAXN];
int cha[MAXN];
vector<int> truy_vet;
vector<int> dsk[MAXN];

namespace sub1 {
    void DFS(int u) {
        visited[u] = true;

        for (auto const &v : dsk[u]) {
            if (v != cha[u]) {
                if (!visited[v]) {
                    cha[v] = u;
                    DFS(v);
                } else if (v == to_tien) {
                    truy_vet.clear();
                    truy_vet.insert(truy_vet.begin(), v);

                    int x = u;
                    while (x != to_tien) {
                        truy_vet.insert(truy_vet.begin(), x);
                        x = cha[x];
                    }

                    if (truy_vet.size() == 4) {
                        for (auto const &i : truy_vet) {
                            cout << i << ' ';
                        }
                        exit(0);
                    } else {
                        continue;
                    }
                }
            } 
        }
    }

    void driver() {
        FOR(i, 1, n) {
            memset(visited, 0, sizeof(visited));
            to_tien = i;
            DFS(i);
        }

        cout << -1;
    }
}

namespace sub2 {
    void driver() {
        
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        dsk[a].push_back(b);
        dsk[b].push_back(a);
    }

    if (n <= 500) {
        sub1::driver();
    }

    return 0;
}