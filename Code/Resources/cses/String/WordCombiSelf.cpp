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

static const int alphabet_size = 26;

struct trie {
    array<trie *, alphabet_size> children;
    bool is_word;
};

trie* get_node()
{
    trie *cur = new trie;
    cur->is_word = false;
    for (int i = 0; i < alphabet_size; i++){
        cur->children[i] = NULL;
    }
    return cur;
}

void insert(trie *root, string &str)
{
    trie *cur = root;
    for (int i = 0; i < str.size(); i++)
    {
        int index = int(str[i] - 'a');
        if (cur->children[index] == NULL) {
            cur->children[index] = get_node();
        }
        cur = cur->children[index];
    }
    cur->is_word = true;
}

// bool search(trie *root, string &str) // only for ref, not in use
// {
//     trie *cur = root;
//     for (int i = 0; i < str.size(); i++)
//     {
//         int index = int(str[i] - 'a');
//         if (cur->children[index] == NULL) {
//             return false;
//         }
//         cur = cur->children[index];
//     }
//     if (cur->is_word == true) {
//         return true;
//     }
//     else {
//         return false;
//     }
// }

int wordBreak(string &s, vector<string>& words) {
    //dict = ['leet', 'leetc', 'ode']
    //s = "leetcode"
    //dp[0] = 1; // 1 way of creating empty string
    // ""
    // 1 0 0 0 1 1 0 0 0 1 ... 1
    // "leet"
    // 1000 * 20 -> trie
    // s * depth -> 300 * 20
    trie *root = get_node();
    for (string word : words) {
        insert(root, word);
    }
    int n = s.length();
    vector<ll> dp(n + 1, 0);
    dp[0] = 1; // meaning we can create empty string for sure with words
    for (int i = 0; i < n; i++) {
        if (dp[i]) {
            trie *cur = root;
            for (int j = 0; (i + j) < n && cur != NULL; j++) {
                int index = i + j;
                cur = cur->children[s[index] - 'a'];
                if (cur != NULL && cur->is_word) {
                    dp[index + 1] += dp[i];
                    dp[index + 1] %= mod;
                }
            }
        }
    }
    return dp[n];
}
 
void solve()
{
	string str;
	cin >> str;
	vector<string> words;
	int k;
	cin >> k;
	while(k--) {
		string word;
		cin >> word;
		words.push_back(word);
	}
	cout << wordBreak(str, words);

}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}