#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
 
void sieve(ll n)
{
    prime.resize(n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (prime[i] && i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}
 
template<typename T>
std::istream& operator>>(std::istream&in, std::vector<T>& v) {
    for (T& x : v)
        in >> x;
    return in;
}
 
template<typename T>
std::ostream& operator<<(std::ostream&out, std::vector<T>& v) {
    for (const T& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
    return out;
}
 
void solve()
{
    // trie can also be implemented as an array
    // nxt[nodes][26], all -1
    // only tells that at depth i, the char is present or not
    // for other info such as is_word etc we need more arrays
    int depth = 1e5; //max word size
    int trie[node][26];
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}


/*

class Trie {
public:
    vector<vector<int>> nxt;
    vector<bool> is_word;
    int N;

    Trie() {
        nxt = vector<vector<int>> (1, vector<int> (26, 0));
        is_word = vector<bool> (1, false); 
        N = 0;
    }
    
    void insert(string word) {
        int node = 0;
        for (char ch : word) {
            if (nxt[node][ch - 'a'] == 0) {
                nxt.emplace_back(vector<int> (26, 0));
                is_word.push_back(false);
                nxt[node][ch - 'a'] = ++N;
            }
            node = nxt[node][ch - 'a'];
        }
        is_word[node] = true;
    }

    int dfs(int node, int i, string &word) { //return the node
        if (i == word.length()) {
            return node;
        }
        int nxt_node = nxt[node][word[i] - 'a'];
        if (nxt_node != 0) {
            return dfs(nxt_node, i + 1, word);
        }
        return 0;     
    }

    bool search(string word) {
        return is_word[dfs(0, 0, word)];
    }
    
    bool startsWith(string prefix) {
        return dfs(0, 0, prefix) != 0;
    }
};

*/