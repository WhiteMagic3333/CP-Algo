class Solution {
public:
    double ratio (int i, int j) {
        return (i * 1.00) / j;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> p;
        int i = 0;
        for (auto c : classes) {
            double old = ratio(c[0], c[1]);
            double new_ratio = ratio(c[0] + 1, c[1] + 1);
            p.push({new_ratio - old, i++});
        }
        while(extraStudents--) {
            i = p.top().second;
            p.pop();
            classes[i][0]++;
            classes[i][1]++;            
            p.push({ratio(classes[i][0] + 1, classes[i][1] + 1) - ratio(classes[i][0], classes[i][1]), i});
        }
        double ans = 0;
        for (auto c : classes) {
            ans += ratio(c[0], c[1]);
        }
        return ans / classes.size();
    }
};