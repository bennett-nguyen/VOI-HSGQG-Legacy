#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define forw(i, l, r) for (int i = l; i <= r; i++)
#define fodd(i, l, r) for (int i = l; i >= r; i--)
#define pii pair<int, int>
const int maxn = 1e3+1;

int num_nodes, num_edges, t, k;
int t_min = -1, c_min = INT_MAX;
int d[maxn];
int tx[maxn], sl[maxn];
int parent[maxn];
unordered_map<int, vector<pii>> dsk;

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

void Dijkstra(int start) {
    priority_queue<pii, vector<pii>, cmp> pq;
    memset(d, 0x3f, sizeof(d));
    pq.push(make_pair(start, 0));
    d[start] = 0;

    while (!pq.empty()) {
        pii i = pq.top(); pq.pop();
        int u = i.first;
        int kw = i.second;

        if (kw > d[u]) continue;
        for (auto const &j : dsk[u]) {
            int v = j.first;
            int w = j.second;

            if (d[v] > d[u]+w) {
                d[v] = d[u]+w;
                pq.push(make_pair(v, d[v]));
            }
        }
    }
}

vector<int> cau_hinh;
int TIME = 0;

namespace BruteForce {
    int visited[maxn];
    void DFS(int i=1, int sum=0) {
        for (auto const &j : dsk[i]) {
            if (visited[j.first]) continue;

            visited[j.first] = true;
            sum += j.second;
            cau_hinh.push_back(j.first);

            if (sum <= t_min+c_min) {
                if (j.first == t) {
                    if (TIME+1 < k) TIME++;
                    else if (TIME+1 == k) {
                        cau_hinh.insert(cau_hinh.begin(), 1);
                        cout << cau_hinh.size() << el;
                        for (auto const &k : cau_hinh) {
                            cout << k << ' ';
                        }
                        exit(0);
                    }
                } else {
                    DFS(j.first, sum);
                }
            }

            if (!cau_hinh.empty()) cau_hinh.pop_back();
            visited[j.first] = false;
            sum -= j.second;
        }
    }
}

namespace Khuyen {
    void xuat() {
        TIME++;
        if (TIME != k) return;
        
        int x = t;
        while (x != 1) {
            while (sl[x]) {
                cau_hinh.insert(cau_hinh.begin(), x);
                sl[x]--;
            }

            cau_hinh.insert(cau_hinh.begin(), x);
            x = parent[x];
        }

        while (sl[x]) {
            cau_hinh.insert(cau_hinh.begin(), x);
            sl[x]--;
        }

        cau_hinh.insert(cau_hinh.begin(), x);

        cout << cau_hinh.size() << el;
        for (auto const &i : cau_hinh) {
            cout << i << ' ';
        }

        exit(0);
    }

    void DFS(int i=1, int sum=0) {
        for (auto const &j : dsk[i]) {
            if (tx[j.first] && sum+j.second <= t_min+c_min) {
                if (j.first != i) parent[j.first] = i;
                else sl[j.first]++;
                tx[j.first]--;
                sum += j.second;

                if (j.first == t) {
                    xuat();
                    if (tx[j.first]) DFS(j.first, sum);
                } else {
                    DFS(j.first, sum);
                }

                sum -= j.second;
                tx[j.first]++;
                if (j.first == i) sl[j.first]--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> num_nodes >> num_edges >> t >> k;
    if (t == 1) TIME++;

    forw(i, 1, num_edges) {
        int u, v, w;
        cin >> u >> v >> w;
        tx[v]++;
        dsk[u].push_back(make_pair(v, w));
        c_min = min(c_min, w);
    }

    for (auto &i : dsk) {
        sort(i.second.begin(), i.second.end(),
        [](const pii &a, const pii &b) -> bool {
            return a.first < b.first;
        });
    }

    Dijkstra(1);
    t_min = d[t];
    if (t_min == -1) {
        cout << -1;
        exit(0);
    }

    Khuyen::DFS();
    cout << -1;
    return 0;
}