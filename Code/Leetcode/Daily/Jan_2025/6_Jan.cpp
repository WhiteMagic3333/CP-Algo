vector<int> minOperations(string boxes) {
        //keep it simple
        //full logic before u code
        int n = boxes.size();
        //suf[i] = no. of op to move all balls from from n - 1 to i
        vector<int> ans(n, 0), suf(n + 1, 0);
        int balls = 0;
        for (int i = 0; i < n; i++) {
            ans[i] = (i > 0 ? ans[i - 1] : 0) + balls;
            balls += (boxes[i] == '1');
        }
        balls = 0;
        int moves_right = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += moves_right + balls;
            moves_right = moves_right + balls;
            balls += (boxes[i] == '1');
        }
        return ans;
    }