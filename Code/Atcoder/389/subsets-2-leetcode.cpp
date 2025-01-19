class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	// 2^N = HELPTER
    	// 2^N = RES -> SET

    	// 2^N + 2^N = 2^N(1 + 1)
    	// 2 ^ (N + 1) = 2 ^ N . N



    	int n = nums.size();
    	int mx = (1 << n) - 1;

    	vector<vector<int>> ans;
    	set<vector<int>> pre_ans;

    	for (int i = 0; i < mx; i++) {
    		map<int, int> m;

    		vector<int> cur;

    		for (int j = n - 1; j >= 0; j--) {
    			int k = n - j - 1;
    			if ((1 << j) & (i)) {
    				m[nums[k]]++;
    			}
    		}

    		for (auto &e : m) {
    			int val = e.first;
    			int f = e.second;
    			while(f--) {
    				cur.push_back(val);
    			}
    		}
    		pre_ans.insert(cur);
    	}

    	for (vector<int> &cur_ans : pre_ans) {
    		ans.push_back(cur_ans);
    	}

    	return ans;

    	// 2 ^ n 
    	// (1 << n);
    	// 001 ->1000 = 8



        // 1 2 1
        // 0 0 0

        -> []

        // 0 0 1

        -> [1]

        for n = 3

        0 0 0 = 0 -> []
        0 0 1 = 1 -> [1]
        0 1 0 = 2
        0 1 1
        1 0 0 = 4
        1 0 1
        1 1 0 
      	1 1 1 = 7


      	0 1 0


      	to pick the i'th element 2 ^ (n - i - 1) should be set

    }
};