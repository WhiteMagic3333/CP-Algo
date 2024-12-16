class Solution {
public:
    void process(string &str, int &i, int n, char ch) {
        while(i < n && str[i] != ch) {
            i++;
        }
    }
    void set_max(int &l, int &r, int &d, int i) {
        l = max(l, i);
        r = max(r, i);
        d = max(d, i);
    }
    bool canChange(string start, string target) {
        // _ _ _ _   L L L
        // R R R R _ _ _ _

        // three pointers
        // i for target, j for start, k for max_traversed
        // k = max(j, k)
        // we can also use i for both i and j
        // traversing from left to right
        // if both equal then move forward
        // if not 
        int n = start.length();
        int k = 0;
        // two pointers
        int l = 0, r = 0, d = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] != target[i]) {
                set_max(l, r, d, i);
                process(start, l, n, 'L');
                process(start, r, n, 'R');
                process(start, d, n, '_');
                if (target[i] == '_') {
                    //go through R and get _
                    //swap R and _
                    //if L found then return false
                    if (l < d || d == n) {
                        return false;
                    }
                    swap(start[r], start[d]);
                    r++;
                    d++;
                } else if (target[i] == 'L') {
                    //go through _ and find L
                    //swap L and _
                    //if R found then return false
                    if (l == n || r < l) {
                        return false;
                    }
                    swap(start[l], start[d]);
                    l++;
                    d++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};