#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 2001;

int n;
map<string, int> mp;
vector<int> dsk[MAXN];
int depth[MAXN];

void DFS(int u) {
    for (auto const &v : dsk[u]) {
        depth[v] = depth[u]+1;
        DFS(v);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    int idx = 1;
    FOR(i, 1, n) {
        string name1, buff, name2;
        cin >> name1 >> buff >> name2;

        transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
        transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
    
        if (!mp[name1]) {
            mp[name1] = idx;
            idx++;
        }

        if (!mp[name2]) {
            mp[name2] = idx;
            idx++;
        }

        dsk[mp[name2]].push_back(mp[name1]);
    }

    depth[mp["polycarp"]] = 1;
    DFS(mp["polycarp"]);
    cout << *max_element(depth, depth+MAXN);

    return 0;
}