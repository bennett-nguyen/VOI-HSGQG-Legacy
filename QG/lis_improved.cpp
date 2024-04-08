#include<bits/stdc++.h>
using namespace std;

const int maxn=1e7+1;
int n, a[maxn], h[maxn];

void doc() {
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void xuly() {
    int res = 1;
    h[1] = 1;

    for (int i = 2; i <= n; i++) {
        int l = 1, r = res;

        while (l <= r) {
            int m = (l + r) / 2;

            if (a[h[m]] < a[i]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        h[l] = i;
        res = max(res, l);
    }

    cout << res <<endl;
}

int main(){
    doc();
    xuly();
}
