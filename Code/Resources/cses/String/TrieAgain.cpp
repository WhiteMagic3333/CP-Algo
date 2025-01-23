#include<bits/stdc++.h>
using namespace std;

struct Trie {
	Trie* children[26];
	bool is_word;
};

Trie* create_node() {
	Trie* cur = new Trie;
	cur->is_word = false;
	for (int i = 0; i < 26; i++) {
		cur->children[i] = NULL;
	}
	return cur;
}

void insert(Trie* root, string &word) {
	Trie* cur = root;
	for (char ch : word) {
		if (cur->children[ch - 'a'] == NULL) {
			cur->children[ch - 'a'] = create_node();
		}
		cur = cur->children[ch - 'a'];
	}
	cur->is_word = true;
}

bool search(Trie* root, string &key) {
	Trie* cur = root;
	for (char ch : key) {
		if (cur->children[ch - 'a'] == NULL) {
			return false;
		}
		cur = cur->children[ch - 'a'];
	}
	return cur->is_word;
}

int main() {
	Trie* root = create_node();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		insert(root, word);
	}
	string to_be_searched;
	cin >> to_be_searched;
	if (search(root, to_be_searched)) {
		cout << "Found";
	} else {
		cout << "Not found";
	}
}

