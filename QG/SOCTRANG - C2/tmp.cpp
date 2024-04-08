int n, m;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
struct re{
    int u, v;
};
bool in(int i, int j){
    return (i >= 1 && i <= m && j >= 1 && j <= n);
}
int bfs(vector<vector<int>> a, int u, int v, int d){
    int cnt = 1;
    queue<re> q;
    q.push({u, v});
    vector<vector<bool>> vs(m + 3, vector<bool>(n + 3, 0));
    vs[u][v] = 1;
    while(!q.empty()){
        const re x = q.front();
        q.pop();
        
        L0(k, 4){
            int i = x.u + dx[k];
            int j = x.v + dy[k];
            if(in(i, j) && a[i][j] % d == 0 && !vs[i][j])
                q.push({i, j}),
                cnt++,
                vs[i][j] = 1;
        }
    }
    return cnt;
}
void sub1(vector<vector<int>> a){
    int ans = 1;
    L(i, 1, m)
        L(j, 1, n){
            int t = a[i][j];
            L(k, 2, sqrt(a[i][j])){
                if(t % k == 0){

                    while(t % k ==0){
                         t /= k;
                    }
                ans = max(ans, bfs(a, i, j, k));
                // if(ans < bfs(a, i, j, k))
                // cout << i _ j _ k _ a[i][j] _ bfs(a, i, j, k) << endl;
                }
            }
            if(t > 1){
                ans = max(ans, bfs(a, i, j, t));
                // if(ans < bfs(a, i, j, t))
                // cout << i _ j _ t << endl;
            }
        }
    cout << ans;
}