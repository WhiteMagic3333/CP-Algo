class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto e : nums) {
            pq.push(e);
        }
        int ans = 0;
        while(pq.top() < k) {
            ans++;
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(x * 2 + y);
        }
        return ans;
    }
};