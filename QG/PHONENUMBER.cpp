#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

struct Node {
    bool endmark = false;
    Node *next[10];

    Node() {
        FOR(i, 0, 9) {
            next[i] = NULL;
        }
    }
};

Node *root;

void insert(string st) {
    Node *curr = root;

    for (auto const &c : st) {
        int idx = c - '0';
        if (curr -> next[idx] == NULL) {
            curr -> next[idx] = new Node();
        }

        curr = curr -> next[idx];
    }

    curr -> endmark = true;
}

bool search(Node *curr) {
    FOR(i, 0, 9) {
        if (curr -> next[i] != NULL) {
            if (curr -> endmark) return true;
            if (search(curr -> next[i])) return true;
        } 
    }

    return false;
}

void del(Node *curr) {
    FOR(i, 0, 9) {
        if (curr -> next[i] != NULL) {
            del(curr -> next[i]);
        }
    }

    delete(curr);
}

int t, n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif

    cin >> t;

    while(t--) {
        root = new Node();
        cin >> n;

        while (n--) {
            string tmp;
            getline(cin >> ws, tmp);
            insert(tmp);
        }

        if (search(root)) cout << "NO" << '\n';
        else cout << "YES" << '\n';
        del(root);
    }

    return 0;
}