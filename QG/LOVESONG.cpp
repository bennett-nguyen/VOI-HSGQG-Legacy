#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 10001;

int A, B, cnt = 0, TIME = 0;
int a[MAXN], b[MAXN], trai[MAXN], phai[MAXN];
int visited[MAXN];

bool ghep_duoc(int i) {
    if (visited[i] == TIME) return false;
    visited[i] = TIME;

    FOR(j, 1, B) {
        if (a[i] == b[j]) continue;
        if (phai[j] == 0 || ghep_duoc(phai[j])) {
            trai[i] = j;
            phai[j] = i;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    cin >> A >> B;

    FOR(i, 1, A) cin >> a[i];
    FOR(i, 1, B) cin >> b[i];

    FOR(i, 1, A) {
        FOR(j, 1, B) {
            if (a[i] != b[j] && phai[j] == 0) {
                trai[i] = j;
                phai[j] = i;
                cnt++;
                break;
            }
        }
    }

    FOR(i, 1, A) {
        if (trai[i] == 0) {
            TIME++;
            cnt += ghep_duoc(i);
        }
    }

    cout << cnt;
    return 0;
}