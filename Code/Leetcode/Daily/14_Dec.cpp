class Solution {
public:
    long long continuousSubarrays(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 0;
        long long ans = 0;
        multiset<int> s;
        while(i < n && j < n) {
            //conditions
            while(s.size() > 0) {
                int mn = *(s.begin());
                int mx = *(s.rbegin());
                if (abs(arr[j] - mn) > 2 || abs(arr[j] - mx) > 2) {
                    s.erase(s.find(arr[i]));
                    i++;
                } else {
                    break;
                }
            }
            //
            s.insert(arr[j]);
            ans += s.size();
            j++;
        }
        return ans;
    }
};