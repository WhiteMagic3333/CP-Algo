class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = right;
        array<bool, 1000002> prime;
        fill_n(prime.begin(), right + 1, true);
        prime[0] = prime[1] = false;
        for (long long i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;                    
                }
            }
        }
        vector<int> ans = {-1, -1};
        int diff = 1e9, last = 0;
        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                if (last && (i - last) < diff) {
                    diff = i - last;
                    ans = {last, i};
                }
                last = i;
            }
        }
        return ans;
    }
};