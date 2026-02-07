class Solution {
public:
    struct Line {
        long long m, c; 
        double xStart;
    };

    struct ConvexHull {
        deque<Line> dq;

        double intersect(const Line& l1, const Line& l2) {
            return (double)(l2.c - l1.c) / (double)(l1.m - l2.m);
        }

        void add(long long m, long long c) {
            Line cur;
            cur.m = m;
            cur.c = c;
            cur.xStart = 0;

            while (!dq.empty()) {
                cur.xStart = intersect(dq.back(), cur);
                if (cur.xStart <= dq.back().xStart)
                    dq.pop_back();
                else
                    break;
            }

            if (dq.empty())
                cur.xStart = -1e18;

            dq.push_back(cur);
        }

        long long get(long long x) {
            while (dq.size() > 1 && dq[1].xStart <= x)
                dq.pop_front();
            return dq.front().m * x + dq.front().c;
        }
    };

    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        const long long INF = LLONG_MAX / 4;
        vector<long long> prev(n + 1, INF), cur(n + 1, INF);

        prev[0] = 0;

        for (int part = 1; part <= k; part++) {
            ConvexHull hull;
            fill(cur.begin(), cur.end(), INF);

            for (int t = part - 1; t < n; t++) {
                if (prev[t] == INF) continue;

                long long m = -pref[t];
                long long c = prev[t] + (pref[t] * pref[t] - pref[t]) / 2;
                hull.add(m, c);
            }

            for (int i = part; i <= n; i++) {
                long long x = pref[i];
                long long best = hull.get(x);
                cur[i] = best + (x * x + x) / 2;
            }

            prev.swap(cur);
        }

        return prev[n];
    }
};
