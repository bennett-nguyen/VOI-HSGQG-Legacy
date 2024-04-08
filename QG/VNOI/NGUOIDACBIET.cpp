#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e5+1;

int n, k, s, m;
unordered_map<string, int> cnt;
unordered_map<string, set<string>> dsk;
unordered_map<string, bool> is_special;
stack<string> q;
set<string> res;


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> k >> s >> m;

    FOR(i, 1, s) {
        string tmp;
        cin >> tmp;
        q.push(tmp);
        res.insert(tmp);
        is_special[tmp] = true;
    }

    FOR(i, 1, m) {
        string name1, name2;
        cin >> name1 >> name2;
        dsk[name1].insert(name2);
        dsk[name2].insert(name1);
    }

    while (!q.empty()) {
        string top = q.top(); q.pop();
        
        for (auto const &child : dsk[top]) {
            if (is_special[child]) continue;
            cnt[child]++;

            if (cnt[child] == k) {
                q.push(child);
                res.insert(child);
                is_special[child] = true;
            }
        }
    }

    cout << res.size() << el;
    for (auto const &i : res) {
        cout << i << ' ';
    }

    return 0;
}