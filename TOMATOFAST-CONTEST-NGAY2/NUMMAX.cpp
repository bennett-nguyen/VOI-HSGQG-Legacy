#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e5+1;

int n, b, res = 0, idx = -1;
bool ok = false;
vector<int> a, b_pos;

int tinh() {
    int res = 0;
    int en = b_pos.size();

    for (int i = 0; i < (int)b_pos.size(); i++) {
        int current_b = b_pos[i];
        int before_b = current_b+1;
        res += before_b;

        if (current_b+1 == n) break;
        if (i != en-1) {
            int next_b = b_pos[i+1];
            int after_b = next_b - current_b - 1;
            res += before_b * after_b;
        } else {
            int after_b = (int)a.size() - 1 - current_b;
            res += before_b * after_b;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> b;
    while (n--) {
        int tmp;
        cin >> tmp;
        idx++;

        if (tmp <= b) {
            a.push_back(tmp);
            if (tmp == b) {
                ok = true;
                b_pos.push_back(idx);
            }
        } else {
            if (ok) res += tinh();
            idx = -1;
            ok = false;
            a.clear();
            b_pos.clear();
        }
    }

    if (ok) res += tinh();
    cout << res;
    return 0;
}