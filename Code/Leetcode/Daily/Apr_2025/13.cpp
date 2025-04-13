class Solution {
public:
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        //primes are 2, 3, 5, 7
        //even are 2, 4, 6, 8 (and 0 for non MSD)
        long long odd_positions = n / 2;
        long long even_positions = n - odd_positions;
        long long ans = 1, mod = 1e9 + 7;
        ans *= binpow(4, odd_positions, mod);
        ans %= mod;
        ans *= binpow(5, even_positions, mod);
        ans %= mod;
        return ans;
    }
};