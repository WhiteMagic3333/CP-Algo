class Solution {
public:
    void split_words(string str, vector<string> &words) {
        string word = "";
        str += ' ';
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                word += str[i];
            } else {
                words.push_back(word);
                word = "";
            }
        }
    }

    bool is_prefix(string str, string &word) {
        //online search if this is pass by reference or not
        //for loop 2nd type for (auto x : y)
        int len = str.length();
        if (len <= word.length()) {
            for (int i = 0; i < len; i++) {
                if (str[i] != word[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        //since the constraints are low, we can implement brute force,
        //however for bigger constraints we can use trie
        vector<string> words;
        split_words(sentence, words);
        for (int i = 0; i < words.size(); i++) {
            if (is_prefix(searchWord, words[i])) {
                return i + 1;
            }
        }
        return -1;
    }
};