#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 2e5+1;

int subtask, n, k;
int arr[MAXN];

map<int, int> mp;

int f(int n) {
    if (n == 1 || n == 0) return 1;
    return n * f(n-1);
}

void sub1() {
    int res = 0;

    FOR(i, 1, n) {
        int a; cin >> a;
        mp[a]++;
    }

    for (auto const &i : mp) {
        res += f(i.second);
    }

    cout << res;
}


vector<int> perm;

void sub2() {
    FOR(i, 1, n) {
        cin >> arr[i];
        perm.push_back(i);
    }

    int res = 0;

    do {
        int hmax = 0, cnt = 0;
        FOR(i, 0, n-1) {
            if (arr[perm[i]] < hmax) {
                hmax = arr[perm[i]];
            } else {
                cnt++;
                if (cnt > k) break;
            }
        }

        cnt++;
    } while (next_permutation(perm.begin(), perm.end()));

    cout << res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("line.inp", "r", stdin);
    freopen("line.out", "w", stdout);
    #endif

    cin >> subtask >> n >> k;
    
    if (subtask == 1) sub1();
    else if (subtask == 2) sub2();
    // else if (subtask == 3) sub3();
    // else if (subtask == 4) sub(4);
    // else sub5();
    
    return 0;
}