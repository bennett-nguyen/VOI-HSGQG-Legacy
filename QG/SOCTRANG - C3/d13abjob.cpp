#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct re {
    int s, a, b;
};

const int MAXN = 1001;

int n, m;
int TIME = 0;
int visited[MAXN], trai[MAXN], phai[MAXN];
re arr[MAXN];

bool ghep_duoc(int i, int e) {
    if (visited[i] == TIME) return false;
    visited[i] = TIME;

    FOR(j, 1, n) {
        if (arr[i].b > arr[j].a || abs(arr[i].s - arr[j].s) > e) continue;
        if (phai[j] == 0 || ghep_duoc(phai[j], e)) {
            trai[i] = j;
            phai[j] = i;
            return true;
        }
    }

    return false;
}

int bin_search() {
    int L = 1, R = 1e7, ans = -1;
    
    while (L <= R) {
        int k = 0;
        int mid = (L+R)/2;
        memset(trai, 0, sizeof(trai));
        memset(phai, 0, sizeof(phai));

        FOR(i, 1, n) {
            TIME++;
            k += ghep_duoc(i, mid);
        }

        if (k + m >= n) {
            ans = mid;
            R = mid-1;
        } else {
            L = mid+1;
        }

    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n >> m;

    FOR(i, 1, n) {
        cin >> arr[i].s >> arr[i].a >> arr[i].b;
    }

    cout << bin_search();
    return 0;
}