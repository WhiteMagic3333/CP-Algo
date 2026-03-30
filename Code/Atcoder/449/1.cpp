string countBalancedNumbers(vector<int> p) {
    int n = p.size();
    
    vector<int> idx(n + 1);
    for (int i = 0; i < n; i++) {
        idx[p[i]] = i;
    }
    
    string result = "";
    int L = n;
    int R = -1;
    
    for (int k = 1; k <= n; k++) {
        L = min(L, idx[k]);
        R = max(R, idx[k]);
        
        if (R - L + 1 == k) {
            result += '1';
        } else {
            result += '0';
        }
    }
    
    return result;
}