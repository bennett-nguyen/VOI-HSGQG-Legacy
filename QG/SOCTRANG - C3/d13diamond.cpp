#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

// f(i, d) -> tai dinh i co bao nhieu vien diamond + nhieu nhat bao nhieu tien
// if f(i, d) >= cij -> f(j, d) = f(i, d) - cij
// f(i, d-1) = f(i, d) + pi

// Dijkstra (1, d) = t -> (i, d) -> (n, *d) >= 0

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    return 0;
}