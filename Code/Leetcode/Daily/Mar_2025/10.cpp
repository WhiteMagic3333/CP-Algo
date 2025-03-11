class Solution {
public:
    bool is_vowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    long long countOfSubstrings(string &word, int &k) {
        long long ans = 0;
        int i = 0, j = 0, v = 0, c = 0, n = word.length();
        unordered_map<char, int> m;
        vector<int> suf_vowels(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (is_vowel(word[i])) {
                suf_vowels[i] = 1 + suf_vowels[i + 1];
            }
        }
        while (j < n) {
            while (j < n && c < k) {
                if (is_vowel(word[j])) {
                    m[word[j]]++;
                    v += m[word[j]] == 1;
                } else {
                    c++;
                }
                j++;
            }
            if (c == k) {
                while (j < n && c == k && v < 5) {
                    if (is_vowel(word[j])) {
                        m[word[j]]++;
                        v += m[word[j]] == 1;
                    } else {
                        c++;
                    }
                    j++;
                }
                while (v == 5 && c == k) {
                    ans += 1 + suf_vowels[j];
                    if (is_vowel(word[i])) {
                        m[word[i]]--;
                        v -= m[word[i]] == 0;
                    } else {
                        c--;
                    }
                    i++;
                }
                while (c > k) {
                    if (is_vowel(word[i])) {
                        m[word[i]]--;
                        v -= m[word[i]] == 0;
                    } else {
                        c--;
                    }
                    i++;
                }
            }
        }
        return ans;
    }
};