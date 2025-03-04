class Solution {
public:
    bool rec(int n, int c) {
        if (n <= 0 || c == 0) {
            return n == 0;
        }
        if (rec(n - c, c / 3) || rec(n, c / 3)) {
            return true;
        }
        return false;
    }

    bool checkPowersOfThree(int n) {
        int c = 1;
        while (c <= n) {
            c *= 3;
        }
        return rec(n, c);
    }
};