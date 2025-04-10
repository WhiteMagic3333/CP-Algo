class Solution {
public:
    long long pow(long long x, int p) {
        long long cur = 1, pw = p;
        while (p--) {
            cur *= x;
        }
        // cout << x << " " << pw << " " << cur << "\n";
        return cur;
    }

    long long fun(long long x, long long s, int limit) {
        if (x <= s) {
            return x == s;
        }
        long long cur = 1, ans = 1, spaces = 0;
        while ((cur * 10) <= x) {
            if (cur > s) {
                ans += limit * pow(limit + 1, spaces);
                spaces++;
            }
            cur *= 10;
        }
        // long long d = (x / cur);
        // ans += d * pow(limit + 1, spaces);
        while (cur > s) {
            long long d = (x / cur) % 10;
            cout << d << " " << spaces << "\n";
            // ans += d * pow(limit + 1, spaces);
            cur /= 10;
            spaces--;
        }
        
        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        // long long _s = stoll(s);
        // return fun(finish, _s, limit) - fun(start - 1, _s, limit);
        cout <<  fun(6654,24,9);
        return 0;
    }
};