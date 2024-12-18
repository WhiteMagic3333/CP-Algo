class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int final_price = prices[i];
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    final_price = prices[i] - prices[j];
                    break;
                }
            }
            ans.push_back(final_price);
        }
        return ans;
    }
    //better
    class Solution {
    public:
        vector<int> finalPrices(vector<int>& prices) {
            stack<int> equal_or_less;
            vector<int> ans(prices.size());
            for (int i = prices.size() - 1; i >= 0; i--) {
                while (equal_or_less.size() && equal_or_less.top() > prices[i]) {
                    equal_or_less.pop();
                }
                ans[i] = prices[i] - (equal_or_less.size() == 0 ? 0 : equal_or_less.top());
                equal_or_less.push(prices[i]);
            }
            return ans;
        }
    };
};