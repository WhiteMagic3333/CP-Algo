//only functions for now

class Solution {
public:
     bool checkIfExist(vector<int>& arr) {
        vector<int> f(3005, 0);
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            f[arr[i] + 1000]++;
        }
        for (int i = 0; i < n; i++) {
            int twice = 2 * arr[i];
            twice += 1000;
            f[arr[i] + 1000]--;
            if (twice >= 0 && twice < 3000 && f[twice]) {
                return true;
            }
            f[arr[i] + 1000]++;
        }
        return false;
    }
};