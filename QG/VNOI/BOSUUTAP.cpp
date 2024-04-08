#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 205, MAXK = 1001;

struct re {
    int Zm, Sm, Mm, Zp, Sp, Mp;
};

struct re_coord {
    int Z, S, M, k = 0;
};

int K, k = 1;
int Z0, S0, M0, Zt, St, Mt;

re dt[MAXK];
bool visited[MAXN][MAXN][MAXN];

queue<re_coord> q;
vector<re_coord> v; 

bool kt(re_coord &con, re bo_doi) {
    con.Z -= bo_doi.Zm;
    con.S -= bo_doi.Sm;
    con.M -= bo_doi.Mm;

    if (min({con.Z, con.S, con.M}) < 0) return false;

    con.Z += bo_doi.Zp;
    con.S += bo_doi.Sp;
    con.M += bo_doi.Mp;

    if (visited[con.Z][con.S][con.M] || max({con.Z, con.S, con.M}) > 4) return false;
    return true;
}

void bfs() {
    visited[Z0][S0][M0] = true;
    q.push({Z0, S0, M0, 0});

    while (!q.empty()) {
        re_coord cha = q.front();
        q.pop();

        FOR(i, 1, k) {
            re_coord con = cha;
            if (!kt(con, dt[i]) || cha.k+1 > K) continue;

            con.k = cha.k+1;
            visited[con.Z][con.S][con.M] = true;
            if (con.Z >= Zt && con.S >= St && con.M >= Mt) v.push_back(con);
            else q.push(con);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> K;
    cin >> Z0 >> S0 >> M0 >> Zt >> St >> Mt;

    while (cin >> dt[k].Zm >> dt[k].Sm >> dt[k].Mm >> dt[k].Zp >> dt[k].Sp >> dt[k].Mp) {
        k++;
    }

    k--;

    bfs();

    if (v.empty()) { cout << -1; }
    else {
        cout << v.size() << '\n';
        sort(v.begin(), v.end(), [](const re_coord &a, const re_coord &b) -> bool { return a.Z < b.Z || (a.Z == b.Z && a.S < b.S) || (a.Z == b.Z && a.S == b.S && a.M < b.M); });
        for (auto const &i : v) {
            cout << i.Z << ' ' << i.S << ' ' << i.M << ' ' << i.k << '\n'; 
        }
    }

    return 0;
}
