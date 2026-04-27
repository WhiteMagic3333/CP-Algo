#include <string>
#include <vector>

using namespace std;

class Solution {
    long long countValid(int idx, bool tight_l, bool tight_r, const string& pattern, const string& L, const string& R) {
        if (idx == 16) return 1;

        if (!tight_l && !tight_r) {
            long long ways = 1;
            for (int i = idx; i < 16; ++i) {
                if (pattern[i] == '?') ways *= 10;
            }
            return ways;
        }

        int min_d = tight_l ? (L[idx] - '0') : 0;
        int max_d = tight_r ? (R[idx] - '0') : 9;
        long long count = 0;

        if (pattern[idx] != '?') {
            int d = pattern[idx] - '0';
            if (d >= min_d && d <= max_d) {
                count += countValid(idx + 1, tight_l && (d == min_d), tight_r && (d == max_d), pattern, L, R);
            }
        } else {
            for (int d = min_d; d <= max_d; ++d) {
                count += countValid(idx + 1, tight_l && (d == min_d), tight_r && (d == max_d), pattern, L, R);
            }
        }
        return count;
    }

public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        string L = to_string(l);
        L = string(16 - L.length(), '0') + L;
        string R = to_string(r);
        R = string(16 - R.length(), '0') + R;

        vector<int> path_idx;
        int row = 0, col = 0;
        path_idx.push_back(0);
        for (char c : directions) {
            if (c == 'D') row++;
            else col++;
            path_idx.push_back(row * 4 + col);
        }

        long long total_good = 0;

        for (int a = 0; a < 10; a++) {
            for (int b = a; b < 10; b++) {
                for (int c = b; c < 10; c++) {
                    for (int d = c; d < 10; d++) {
                        for (int e = d; e < 10; e++) {
                            for (int f = e; f < 10; f++) {
                                for (int g = f; g < 10; g++) {
                                    
                                    string pattern(16, '?');
                                    
                                    pattern[path_idx[0]] = '0' + a;
                                    pattern[path_idx[1]] = '0' + b;
                                    pattern[path_idx[2]] = '0' + c;
                                    pattern[path_idx[3]] = '0' + d;
                                    pattern[path_idx[4]] = '0' + e;
                                    pattern[path_idx[5]] = '0' + f;
                                    pattern[path_idx[6]] = '0' + g;

                                    total_good += countValid(0, true, true, pattern, L, R);
                                }
                            }
                        }
                    }
                }
            }
        }

        return total_good;
    }
};