class Solution {
public:
    vector<int> getFinalState(vector<int>& arr, int k, int multiplier) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> p;
        for (int i = 0; i < arr.size(); i++)
        {
            p.push({arr[i], i});
        }
        while(k--) {
            int i = p.top()[1];
            p.pop();
            arr[i] = arr[i] * multiplier;
            p.push({arr[i], i});
        }
        return arr;
    }
};