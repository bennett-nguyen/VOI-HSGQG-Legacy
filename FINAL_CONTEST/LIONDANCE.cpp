#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1e9+1;

int n, delta;
int L[maxn], R[maxn];


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #else
    freopen("LIONDANCE.inp", "r", stdin);
    freopen("LIONDANCE.out", "w", stdout);
    #endif

    cin >> n >> delta;

    FOR(i, 1, n) {
        cin >> L[i];
    }

    FOR(i, 1, n){
        cin >> R[i];
    }
    
    return 0;
}