class Solution {
public:
    int ap_sum(int a) {
        return (a * (a + 1)) / 2;
    }

    int tupleSameProduct(vector<int>& nums) {
        /*f pairs
          1  0
          2  1
          3  2 + 1 = 3
          4  3 + 2 + 1 = 6
        */
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int prod = nums[i] * nums[j];
                m[prod]++;
            }
        }
        int ans = 0;
        for (auto f : m) {
            ans += ap_sum(f.second - 1);
        }
        return ans * 8;
    }
};