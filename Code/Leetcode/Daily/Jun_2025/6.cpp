class Solution {
public:
    char get_smallest_char(map<char, int> &freq) {
        for (auto [ch, f] : freq) {
            if (f > 0) {
                return ch;
            }
        }
        return 'z' + 1;
    }
    string robotWithString(string s) {
        stack<char> st;
        map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            char smallest = get_smallest_char(freq);
            if (st.size() && st.top() <= smallest) {
                ans.push_back(st.top());
                st.pop();
                i--;
                continue;
            } else if (ch > smallest) {
                st.push(ch);
            } else {
                ans.push_back(ch);
            }
            freq[ch]--;
        }
        while (st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};