class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> fa(51, 0), fb(51, 0);
        vector<int> C;
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            if(A[i] == B[i]) {
                ans++;
            } else {
                if (fa[A[i]] < fb[A[i]]) {
                    ans++;
                }
                if (fb[B[i]] < fa[B[i]]) {
                    ans++;
                }
            }
            fa[A[i]]++;
            fb[B[i]]++;
            C.push_back(ans);
        }
        return C;
    }
};