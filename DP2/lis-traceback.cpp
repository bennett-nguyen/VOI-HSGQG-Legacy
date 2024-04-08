#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int maxn = 1001;

int n;
int max_ans = INT_MIN;
int dp[maxn], arr[maxn], parent[maxn];
stack<int> st;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;
    cin >> arr[1];
    dp[1] = 1;

    FOR(i, 2, n) {
        dp[i] = 1;
        cin >> arr[i];

        FOR(j, 1, i-1) {
            if (arr[i] <= arr[j]) continue;
            if (dp[j]+1 > dp[i]) {
                parent[i] = j;
                dp[i] = dp[j]+1;
            }
        }
    }

    int e = 1;
    FOR(i, 1, n) {
        if (max_ans < dp[i]) {
            e = i;
            max_ans = dp[i];
        }
    }

    do {
        st.push(e);
        e = parent[e];
    } while (e);

    cout << st.size() << el;
    while (st.size()) {
        cout << arr[st.top()] << ' ';
        st.pop();
    }

    return 0;
}