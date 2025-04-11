class Solution {
public:
    bool is_valid(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int total_digits = digits.size();
        if (total_digits % 2) {
            return false;
        }
        int s1 = 0, s2 = 0;
        for (int i = 0; i < total_digits; i++) {
            if (i < (total_digits / 2)) {
                s1 += digits[i];
            } else {
                s2 += digits[i];
            }
        }
        return s1 == s2;
    }

    int countSymmetricIntegers(int low, int high) {
        //cant think of optimized for this
        int ans = 0;
        for (int i = low; i <= high; i++) {
            ans += is_valid(i);
        }
        return ans;
    }
};