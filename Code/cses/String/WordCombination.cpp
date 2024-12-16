#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
const int alphabet_size = 26;


struct trie {
	array<trie *, alphabet_size> children;
	bool is_word;
};

trie* get_node()
{
	trie *cur = new trie;
	cur->is_word = false;
	for (int i = 0; i < alphabet_size; i++)
		cur->children[i] = NULL;
	return cur;
}

void insert(trie *root, string &str)
{
	trie *cur = root;
	for (int i = 0; i < str.size(); i++)
	{
		int index = int(str[i] - 'a');
		if (cur->children[index] == NULL)
			cur->children[index] = get_node();
		cur = cur->children[index];
	}
	cur->is_word = true;
}

bool search(trie *root, string &str)
{
	trie *cur = root;
	for (int i = 0; i < str.size(); i++)
	{
		int index = int(str[i] - 'a');
		if (cur->children[index] == NULL)
			return false;
		cur = cur->children[index];
	}
	if (cur->is_word == true)
		return true;
	else
		return false;
}

void solve()
{
	string given;
	cin >> given;
	int n = given.length();
	int k;// total words
	cin >> k;
	trie *root = get_node();
	for (int i = 0; i < k; i++)
	{
		string str;
		cin >> str;
		insert(root, str);
	}
	vector<ll> dp(n + 1, 0);
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		trie *cur = root;
		for (int j = i; j < n; j++)
		{
			int index = int(given[j] - 'a');
			if(cur->children[index] == NULL)
				break;
			cur = cur->children[index];
			if(cur->is_word)
				dp[i] = (dp[i] + dp[j + 1]) % mod;
		}
	}
	cout << dp[0];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}