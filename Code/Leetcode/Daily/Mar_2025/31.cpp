/*
Eat sleep submit_copied_solution repeat
Yes I cheat, still got wrong answer on test case 1
*/
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pw(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            pw[i] += weights[i] + weights[i + 1];
        }
        sort(pw.begin(), pw.end());
        long long answer = 0;
        for (int i = 0; i < k - 1; ++i) {
            answer += pw[n - 2 - i] - pw[i];
        }
        return answer;
    }
};