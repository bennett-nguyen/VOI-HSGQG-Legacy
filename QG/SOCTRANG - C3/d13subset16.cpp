#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

const int MAXN = 200001;
int n, l, r;
int arr[MAXN];

// subtask 1: bitmask 
// subtask 2: chia doi tap, duyet tren tap a, chat tren tap b
// subtask 3: QHD, goi F(i, s) la tong cua s khi xet den vi tri s -> True / False nghia la ton tai hoac ko ton tai
// F[MAXN][MAXA]

/*
void QHD(int i, int S) {
    if (F[i][S]) return
    
}
*/

// subtask 4: 
// subtask 5: lay L tru di phan tu lon nhat co the den khi tim ra duoc ket qua
// subtask 6: max_ai - min_ai <= R - L, sort ai
// gia su ton tai phuong an gom k phan tu => tong cua k phan tu dau luon <= R => tong cua k phan tu cuoi cung luon >= L
// (1) for k: 1 -> n: neu k phan tu dau <= L && k phan tu cuoi >= R: break va tra ve kq
// (2) tinh tien

namespace sub1 {
    vector<int> truy_vet;

    void run() {
        FOR(mask, 1, (1 << n) - 1) {
            truy_vet.clear();
            int i = 1;
            int tetsumvay = 0;
            int tmp_mask = mask;

            while (tmp_mask) {
                if (tmp_mask & 1) {
                    tetsumvay += arr[i];
                    truy_vet.push_back(i);
                }

                tmp_mask >>= 1;
                i++;
            }

            if (l <= tetsumvay && tetsumvay <= r) {
                cout << truy_vet.size() << el;

                for (auto const &k : truy_vet) {
                    cout << k << ' ';
                }

                break;
            }
        }
    }
}

namespace sub2 {
    struct re {
        int sum = 0;
        vector<int> idx;
    };

    vector<pair<int, int>> a, b;
    vector<re> day_a, day_b;

    void sinh_hoan_vi_a() {
        re tmp;

        FOR(mask, 1, (1 << a.size()) - 1) {
            int i = 0;
            tmp.idx.clear();
            tmp.sum = 0;
            int tmp_mask = mask;

            while (tmp_mask) {
                if (tmp_mask & 1) {
                    tmp.sum += a[i].second;
                    tmp.idx.push_back(a[i].first);
                }

                tmp_mask >>= 1;
                i++;
            }

            day_a.push_back(tmp);
        }
    }

    void sinh_hoan_vi_b() {
        re tmp;
        FOR(mask, 1, (1 << b.size()) - 1) {
            int i = 0;
            tmp.idx.clear();
            tmp.sum = 0;
            int tmp_mask = mask;

            while (tmp_mask) {
                if (tmp_mask & 1) {
                    tmp.sum += b[i].second;
                    tmp.idx.push_back(b[i].first);
                }

                tmp_mask >>= 1;
                i++;
            }

            day_b.push_back(tmp);
        }
    }

    void run() {
        int mid = n / 2;

        FOR(i, 1, mid) {
            a.push_back(make_pair(i, arr[i]));
        }

        FOR(i, mid+1, n) {
            b.push_back(make_pair(i, arr[i]));
        }

        sub2::sinh_hoan_vi_a();
        sub2::sinh_hoan_vi_b();

        sort(day_b.begin(), day_b.begin(), [](const re &a, const re &b) -> bool { return a.sum < b.sum; });
    }
}

namespace sub3 {
    const int MAXS = 1e5+1;
    bool F[81][MAXS];

    void QHD(int i, int S) {


    }

    void run() {

    }
}

namespace sub4 {
    void run() {

    }
}

namespace sub5 {
    int f[MAXN];

    void run() {
        FOR(i, 1, n) {
            f[i] = f[i-1] + arr[i];
        }

        FOR(i, 1, n) {
            int L = i, R = n, ans = n;

            while (L <= R) {
                int mid = (L+R)/2;
                if (f[mid] - f[i-1] >= l) {
                    ans = mid;
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }

            if (f[ans] - f[i-1] <= r) {
                cout << ans-i+1 << el;

                FOR(idx, i, ans) {
                    cout << idx << ' ';
                }

                exit(0);
            }
        }
    }
}

int main() {    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    bool is_sub_4 = true;
    cin >> n >> l >> r;

    FOR(i, 1, n) {
        cin >> arr[i];
        if (i != 1 && arr[i] != arr[i-1]) {
            is_sub_4 = false;
        } 
    }

    if (is_sub_4) {
        sub5::run();
    } else if (n <= 20) {
        sub1::run();
    } else if (n <= 40) {
        sub2::run();
    } else if (n <= 80) {
        sub3::run();
    } else {
        sub5::run();
    }

    return 0;
}