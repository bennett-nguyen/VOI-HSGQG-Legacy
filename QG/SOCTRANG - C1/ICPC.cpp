#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 27;

struct re {
    int d;
    char pos;
};

int n;
int psum[MAXN], penalty[MAXN];
string ans = "";
re arr[MAXN];



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    #ifdef ONLINE_JUDGE
    freopen("icpc.inp", "r", stdin);
    freopen("icpc.out", "w", stdout);
    #endif

    cin >> n;
    FOR(i, 1, n) {
        cin >> arr[i].d;
        arr[i].pos = 'A' + i - 1;
    }
    
    sort(arr+1, arr+1+n, [](const re &a, const re &b) -> bool { return a.d < b.d || (a.d == b.d && a.pos < b.pos); });
    
    int kq_pt = 0;
    FOR(i, 1, n) {
        psum[i] = psum[i-1] + arr[i].d;
        if (psum[i] > 300) break;
        ans += arr[i].pos;
        kq_pt = i;
    }

    FOR(i, 1, kq_pt) {
        penalty[i] += penalty[i-1] + arr[i].d*(kq_pt-i+1);
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       

    cout << kq_pt << ' ' << penalty[kq_pt] << ' ' << psum[kq_pt] << el;
    cout << ans; 
    return 0;
}