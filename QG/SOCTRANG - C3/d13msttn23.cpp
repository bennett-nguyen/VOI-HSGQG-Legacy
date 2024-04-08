#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

// sap xep w => w[1] <= w[2] <= ... <= w[n]
// w[i]*w[j] + t*(w[i]+w[j]) = (w[i]+t)(w[j]+t) - t^2

// w[1] + t >= 0 -> w[i] - w[j] for all j   
// w[1] + t < 0 -> ---- 
//                 |
//                 ---- 

const int MAXN = 1e5+1;

int n, q;
int arr[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> n >> q;
    FOR(i, 1, n) cin >> arr[i];

    
    return 0;
}