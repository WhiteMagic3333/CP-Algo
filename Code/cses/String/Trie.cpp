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
	int n;// total words
	cin >> n;
	trie *root = get_node();
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		insert(root, str);
	}
	// word to be searched
	string q;
	cin >> q;
	if(search(root, q))
		cout << "YES";
	else
		cout << "NO";
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}