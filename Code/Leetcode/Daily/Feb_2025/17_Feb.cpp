class Solution {
    //chef is cooked
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        queue<string> q;
        for (auto &ch : tiles) {
            freq[ch]++;
            if (freq[ch] == 1) {
                string chr;
                chr.push_back(ch);
                q.push(chr);
            }
        }
        int ans = 0, distinct = q.size();
        while(q.size()) {
            int dis = distinct;
            unordered_map<char, int> c_freq = freq;
            string cur = q.front();
            q.pop();
            for (auto &ch : cur) {
                c_freq[ch]--;
            }
            for (auto &f : c_freq) {
                if (f.second > 0) {
                    string chr = "";
                    chr.push_back(f.first);
                    chr += cur;
                    q.push(chr);
                }
            }
            ans++;
        }
        return ans;
    }
};