#include <bits/stdc++.h>
using namespace std;

#define PB push_back

const int MOD = 1e9 + 7;

string S;
int K, I = 1, DP[5005];

vector<int> adj[500005];

struct node {
    int fail, ch[26] = {};
    vector<int> lens;
    string s = "";
} T[500005];

void insert(string s) {
    int x = 1;
    for (int i = 0; i < s.size(); i++) {
        if (T[x].ch[s[i] - 'a'] == 0)
            T[x].ch[s[i] - 'a'] = ++I;
        T[T[x].ch[s[i] - 'a']].s = T[x].s + s[i];
        x = T[x].ch[s[i] - 'a'];
    }
    T[x].lens.PB(s.size());
}

// initializes lens
void dfs(int u) {
    T[u].lens.insert(T[u].lens.end(), T[T[u].fail].lens.begin(), T[T[u].fail].lens.end());
    for (int v : adj[u])
        dfs(v);
}

void build() {
    queue<int> Q;
    int x = 1;
    T[1].fail = 1;
    for (int i = 0; i < 26; i++) {
        if (T[x].ch[i])
            T[T[x].ch[i]].fail = x, Q.push(T[x].ch[i]);
        else
            T[x].ch[i] = 1;
    }
    while (!Q.empty()) {
        x = Q.front(); Q.pop();
        for (int i = 0; i < 26; i++) {
            if (T[x].ch[i])
                T[T[x].ch[i]].fail = T[T[x].fail].ch[i], Q.push(T[x].ch[i]);
            else
                T[x].ch[i] = T[T[x].fail].ch[i];
        }
    }
    for (int i = 2; i <= I; i++)
        adj[T[i].fail].PB(i);
    dfs(1);
}

int run(string s) {
    DP[0] = 1;
    for (int i = 1, x = 1; i < s.size(); i++) {
        x = T[x].ch[s[i] - 'a'];
        for (int l : T[x].lens)
            if (l <= i)
                DP[i] = (DP[i] + DP[i - l]) % MOD;
    }
    return DP[s.size() - 1];
}

int main() {
    cin >> S >> K;
    for (int i = 0; i < K; i++) {
        string s; cin >> s;
        insert(s);
    }

    build();
    cout << run(" " + S) << '\n';
}