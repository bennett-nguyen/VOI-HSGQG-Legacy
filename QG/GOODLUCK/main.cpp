#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

int n;

struct cmp {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

priority_queue<int, vector<int>, cmp> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n;

    while (n--) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while (pq.size()) {
        cout << pq.top() << el;
        pq.pop();
    }
    
    return 0;
}