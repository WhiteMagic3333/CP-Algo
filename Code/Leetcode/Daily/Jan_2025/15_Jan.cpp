class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c2 = __builtin_popcount(num2);
        int lz1 = __builtin_clz(num1);
        bitset<32> a(num1);
        int x = 0;
        for (int i = 31 - lz1; i >= 0 && c2 > 0; i--) {
            if (a[i] == 1) {
                x = x | (1 << i);
                c2--;
            }
        }
        for (int i = 0; i < 32 && c2 > 0; i++) {
            if (a[i] == 0) {
                x = x | (1 << i);
                c2--;
            }
        }
        return x;
    }
};