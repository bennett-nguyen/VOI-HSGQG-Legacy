#include <bits/stdc++.h>
using namespace std;

#define el endl
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 1e4+1;

int n, x, res = 0;
int arr[MAXN];
bool chosen[MAXN];

void sub1() {
    sort(arr+1, arr+1+n);

    int cnt = n;
    FOD(i, n, 1) {
        bool ok = false;
        if (chosen[i]) continue;
        chosen[i] = true;

        if (arr[i] == x) {
            res++;
            cnt--;
            continue;
        } else if (cnt == 1) {
            res++;
            break;
        }

        cnt--;
        FOD(j, i-1, 1) {
            if (!chosen[j] && arr[i] + arr[j] <= x) {
                res++;
                chosen[j] = true;
                cnt--;
                ok = true;
                break;
            }
        }

        if (!ok) res++;
    }

    cout << res;
}

void sub2() {
    sort(arr+1, arr+1+n);

    int j = n;
    int res = 0;

    FOR(i, 1, n) {
        while (arr[i] + arr[j] > x) {
            j--;
            res++;
        }

        if (i > j) break;
        res++;
        j--;
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    #ifdef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    cin >> n >> x;
    FOR(i, 1, n) cin >> arr[i];

    sub2();
    return 0;
}