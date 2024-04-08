#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 2e5+1;

int T, n;
int TIME;
int a[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> T;

    while (T--) {
        cin >> n;

        FOR(i, 1, n) {
            a[i] = i;
            cin >> TIME;

            int j = i;
            while (TIME--) {
                swap(a[j], a[j-1]);
                j--;
            }
        }

        FOR(i, 1, n) {
            cout << a[i] << ' ';
        }

        cout << el;
    }

    return 0;
}