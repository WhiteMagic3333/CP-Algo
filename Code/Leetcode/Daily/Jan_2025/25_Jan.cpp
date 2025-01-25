class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sim(n), ans(n); //smallest it can make
        vector<int> cp = nums;
        sort(cp.begin(), cp.end());
        multiset<int> pq;
        for (auto i : cp) {
            pq.insert(i);
        }
        sim[0] = cp[0];
        for (int i = 1; i < n; i++) {
            if ((cp[i] - cp[i - 1]) <= limit) {
                sim[i] = sim[i - 1];
            } else {
                sim[i] = cp[i];
            }
        }
        for (int i = 0; i < n; i++) {
            int index = lower_bound(cp.begin(), cp.end(), nums[i]) - cp.begin();
            auto it = pq.lower_bound(sim[index]);
            ans[i] = *it;
            pq.erase(it);
        }
        return ans;
    }
};