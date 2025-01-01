class Solution {
public:

    string repeatLimitedString(string str, int lim) {
        int n = str.length();
        vector<int> freq(26, 0);
        stack<char> s;
        for (char ch : str) {
            freq[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                s.push('a' + i);
            }
        }
        string ans = "";
        while(s.size()) {
            char biggest_ch = s.top();
            //print big untill lim then get a single element
            int i = biggest_ch - 'a';
            int take = min(freq[i], lim);
            freq[i] -= take;
            s.pop();
            while(take--) {
                ans += biggest_ch;
            }
            if (freq[i] && s.size()) {
                char next_big = s.top();
                ans += next_big;
                freq[next_big - 'a']--;
                if (freq[next_big - 'a'] == 0) {
                    s.pop();
                }
                s.push(biggest_ch);
            }
        }
        return ans;
    }
};