class Solution {
public:
    int ap_sum(int n) {
        return n * (n + 1) / 2;
    }
    int differenceOfSums(int n, int m) {
        //can be done in O(1)
        int num2 = ap_sum(n / m) * m;
        int num1 = ap_sum(n) - num2;
        return num1 - num2;
    }
};