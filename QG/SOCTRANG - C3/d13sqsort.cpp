#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

/*
vector<int> dat[45];

void sort(int level) {
    if (level == 2*n+1) return;

    if (level % 2 == 0) {
        chon x lam trung vi
        for i: 0 -> dat[level].size()-1
            if (dat[i] <= x) {
                sol.pop(level)
                sol.pop(level+1)
                dat[level+2].push_back(dat[level][i])
            } else {
                sol.pop(level)
                dat[level+1].push_back(dat[level][i])
            }

        dat[level].clear()
        sort(level+2); sort(level+1);
    } else {
        fod i: dat[level].size()-1 -> 0
            sol.pop(level)
            dat[level+1].push_back(dat[level][i])

        dat[level].clear()
        sort(level+1);
    }
}

-- Driver code
sort(1);
*/

int n, k;
vector<int> dat[45], sol;

int tim_trung_vi(vector<int> v) {
    sort(v.begin(), v.end());
    int mid = (v.size()-1)/2;
    return v[mid];
}

void sort(int level) {
    if (level == 2*n+1) return;

    if (level % 2 == 0) {
        int x = tim_trung_vi(dat[level]);
        for (auto const &i : dat[level]) {
            if (i <= x) {
                sol.push_back(level);
                sol.push_back(level+1);
                dat[level+2].push_back(i);
            } else {
                sol.push_back(level);
                dat[level+1].push_back(i);
            }
        }

        dat[level].clear();
        sort(level+2);
        sort(level+1);
    } else {
        FOD(i, dat[level].size()-1, 0) {
            sol.push_back(level);
            dat[level+1].push_back(dat[level][i]);
        }

        dat[level].clear();
        sort(level+1);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n >> k;

    FOR(i, 1, k) {
        int tmp;
        cin >> tmp;
        dat[1].push_back(tmp);
    }

    sort(1);

    for (auto const &i : sol) {
        cout << i << ' ';
    }

    return 0;
}