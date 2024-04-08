#include <iostream>
#include <queue>
using namespace std;
 
// a[i][j] = true n?u ? ô (i, j) có quân c?
bool a[201][201];
bool visited[201][201];
 
struct pack {
    int i, j; // To? d? c?a ô
    int d; // Ð? dài du?ng di
};
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, p, q, s, t;
    cin >> n >> m >> p >> q >> s >> t;
    while (m--) {
        int x, y; cin >> x >> y;
        a[x][y] = true;
    }
 
    // BFS d? tìm du?ng di
 
    queue<pack> Q;
    // Thêm ô (p, q) vào queue v?i d? dài du?ng di là 0
    Q.push({p, q, 0});
    visited[p][q] = true;
    while (!Q.empty()) {
        // L?y u ? d?u queue, sau dó xóa u trong queue
        pack u = Q.front();
        int i = u.i, j = u.j;
        Q.pop();
 
        // Duy?t theo hu?ng dông nam
        for (int k=1; i+k<=n && j+k<=n; k++) if (!a[i+k][j+k]) {
            int i1 = i+k, j1 = j+k;
 
            // Ô (i1, j1) chua du?c duy?t
            if (!visited[i1][j1]) {
 
                // Thêm (i1, j1) vào queue
                Q.push({i1, j1, u.d+1});
                visited[i1][j1] = true;
 
                // N?u (i1, j1) là ô dích thì ta xu?t k?t qu?,
                // r?i d?ng chuong trình
                if (i1==s && j1==t) {
                    cout << u.d+1;
                    return 0;
                }
            }
        } else break;
 
        // Duy?t theo hu?ng tây b?c
        for (int k=1; i-k>=1 && j-k>=1; k++) if (!a[i-k][j-k]) {
            int i1 = i-k, j1 = j-k;
            if (!visited[i1][j1]) {
                Q.push({i1, j1, u.d+1});
                visited[i1][j1] = true;
                if (i1==s && j1==t) {
                    cout << u.d+1;
                    return 0;
                }
            }
        } else break;
 
        // Duy?t theo hu?ng dông b?c
        for (int k=1; i-k>=1 && j+k<=n; k++) if (!a[i-k][j+k]) {
            int i1 = i-k, j1 = j+k;
            if (!visited[i1][j1]) {
                Q.push({i1, j1, u.d+1});
                visited[i1][j1] = true;
                if (i1==s && j1==t) {
                    cout << u.d+1;
                    return 0;
                }
            }
        } else break;
 
        // Duy?t theo hu?ng tây nam
        for (int k=1; i+k<=n && j-k>=1; k++) if (!a[i+k][j-k]) {
            int i1 = i+k, j1 = j-k;
            if (!visited[i1][j1]) {
                Q.push({i1, j1, u.d+1});
                visited[i1][j1] = true;
                if (i1==s && j1==t) {
                    cout << u.d+1;
                    return 0;
                }
            }
        } else break;
    }
    cout << -1;
    return 0;
}
