#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct Node {
    bool endmark = false;
    Node *next[26+1];
    
    Node() {
        FOR(i, 0, 25) {
            next[i] = NULL;
        }
    }
};

Node *root;

void insert(string st) {
    Node *curr = root;
    for (auto const &c : st) {
        int idx = c - 'a';
        if (curr->next[idx] == NULL) {
            curr->next[idx] = new Node();
        }
        curr = curr->next[idx];
    }

    curr->endmark = true;
}

bool search(string st) {
    Node *curr = root;
    for (auto const &c : st) {
        int idx = c - 'a';
        if (curr->next[idx] == NULL) return false;
        curr = curr->next[idx];
    }

    return true;
}

int n, m;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> n >> m;
    root = new Node();

    while (n--) {
        string tmp;
        getline(cin >> ws, tmp);
        cout << tmp << '\n';
        insert(tmp);
    }

    while (m--) {
        string tmp;
        getline(cin >> ws, tmp);

        // if (search(tmp)) {
        //     cout << "YES" << '\n';
        // } else {
        //     cout << "NO" << '\n';
        // }
    }
    

    return 0;
}