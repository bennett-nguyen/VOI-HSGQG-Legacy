#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long unsigned
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

ll k, X, Y;
ll M;
unordered_map<ll, bool> visited;
unordered_map<ll, ll> d, parent;

ll xoay(ll num)
{
    if (num < 10)
        return num;

    ll ans = 0;
    ll i = 1;

    while (num)
    {
        if (num / 10 != 0)
        {
            ans = ans + (num % 10) * pow(10, i);
            num /= 10;
            i++;
        }
        else
        {
            ans += num;
            break;
        }
    }

    return ans;
}

queue<ll> q;

void BFS(ll start)
{
    d[start] = 0;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        if (u < M && !visited[u + 1])
        {
            visited[u + 1] = true;
            d[u + 1] = d[u] + 1;
            q.push(u + 1);
            parent[u + 1] = u;

            if (u + 1 == Y)
                return;
        }

        ll rotated = xoay(u);
        if (rotated > M || visited[rotated])
            continue;

        visited[rotated] = true;

        q.push(rotated);
        d[rotated] = d[u] + 1;
        parent[rotated] = u;

        if (rotated == Y)
            return;
    }
}

stack<ll> truy_vet;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CXY.inp", "r", stdin);
    freopen("CXY.out", "w", stdout);

    cin >> k >> X >> Y;
    M = pow(10, k);

    BFS(X);

    cout << d[Y] << el;
    ll x = Y;

    while (x)
    {
        truy_vet.push(x);
        x = parent[x];
    }

    while (!truy_vet.empty())
    {
        cout << truy_vet.top() << el;
        truy_vet.pop();
    }

    return 0;
}