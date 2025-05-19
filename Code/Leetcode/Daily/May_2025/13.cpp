class Solution {
public:
    const long long mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        long long ans = s.length();
        vector<long long> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        while (t--) {
            //z to ab &&
            long long z = freq.back();
            ans += z;
            ans %= mod;
            for (int i = 25; i > 0; i--) {
                freq[i] = freq[i - 1];
            }
            freq[0] = z;
            freq[1] += z;
            freq[1] %= mod;
        }
        return ans;
    }
};