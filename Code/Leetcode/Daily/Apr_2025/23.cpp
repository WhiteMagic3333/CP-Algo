class Solution {
public:
    int __sod(int cur) {
        int sum = 0;
        while (cur) {
            sum += cur % 10;
            cur /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> sod;
        int mx = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            int _sod = __sod(i);
            sod[_sod]++;
            mx = max(mx, sod[_sod]);
        }
        for (auto [sum, freq] : sod) {
            if (freq == mx) {
                ans++;
            }
        }
        return ans;
    }
};