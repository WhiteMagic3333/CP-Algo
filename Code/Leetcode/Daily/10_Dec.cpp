class Solution {
public:
    int maximumLength(string str) {
        int n = str.length();
        char ch = 'A';
        int ans = -1;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            for (int freq = 1; freq < 50; freq++) {
                int f = freq, count = 0;
                for (int i = 0; i < n; i++) {
                    if (str[i] == ch) {
                        int len = 0;
                        for (int j = i; j < n; j++) {
                            if (str[j] != ch || len >= freq) {
                                break;
                            }
                            len++;
                        }
                        if (len >= freq) {
                            count++;
                        }
                    }
                }
                if (count > 2) {
                    // cout << freq << " " << ch << '\n';
                    ans = max(ans, freq);
                }
            }
        }
        return ans;
    }
};