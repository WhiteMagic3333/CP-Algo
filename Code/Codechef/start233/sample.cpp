int findMinimumIdleness(string s, int k) {
    int n = s.length(), low = 1, high = n, ans = n;
    
    while (low <= high) {
        int mid = low + (high - low) / 2, ops = 0;
        
        if (mid == 1) {
            int d1 = 0, d2 = 0;
            for (int i = 0; i < n; ++i) s[i] == (i % 2 ? 'b' : 'a') ? d1++ : d2++;
            ops = min(d1, d2);
        } else {
            for (int i = 0, j; i < n; i = j) {
                for (j = i; j < n && s[j] == s[i]; j++);
                ops += (j - i) / (mid + 1);
            }
        }
        
        if (ops <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return ans;
}