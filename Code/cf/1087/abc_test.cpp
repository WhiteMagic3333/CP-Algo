#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Maximum K will be around 90, so size 105 is safely bounded.
long long len[105];
long long tot[105][26];

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string X, Y;
    if (!(cin >> X >> Y)) return 0;

    int Q;
    if (!(cin >> Q)) return 0;

    // Base Case 1: S_1
    len[1] = X.length();
    for (int i = 0; i < X.length(); ++i) {
        tot[1][X[i] - 'a']++;
    }

    // Base Case 2: S_2
    len[2] = Y.length();
    for (int i = 0; i < Y.length(); ++i) {
        tot[2][Y[i] - 'a']++;
    }

    // Compute properties of S_k up until length crosses 10^18
    int K = 2;
    while (len[K] < 1000000000000000000LL) {
        K++;
        len[K] = len[K-1] + len[K-2];
        for (int c = 0; c < 26; ++c) {
            tot[K][c] = tot[K-1][c] + tot[K-2][c];
        }
    }

    // Precompute Prefix Counts for strings X and Y 
    vector<vector<int>> prefX(X.length() + 1, vector<int>(26, 0));
    for (int i = 0; i < X.length(); ++i) {
        for (int c = 0; c < 26; ++c) prefX[i+1][c] = prefX[i][c];
        prefX[i+1][X[i] - 'a']++;
    }

    vector<vector<int>> prefY(Y.length() + 1, vector<int>(26, 0));
    for (int i = 0; i < Y.length(); ++i) {
        for (int c = 0; c < 26; ++c) prefY[i+1][c] = prefY[i][c];
        prefY[i+1][Y[i] - 'a']++;
    }

    // Lambda to find occurrences of char `c` in the first `p` characters
    auto get_count = [&](long long p, int c) -> long long {
        if (p == 0) return 0;
        
        long long ans = 0;
        int k = K;
        
        while (k > 2) {
            if (p == len[k]) {
                ans += tot[k][c];
                return ans;
            }
            if (p <= len[k-1]) {
                k = k - 1; // Required segment is strictly within S_{k-1}
            } else {
                ans += tot[k-1][c]; // Take all elements of S_{k-1}
                p -= len[k-1];      // Deduct accounted length 
                k = k - 2;          // Move on to process the remaining part in S_{k-2}
            }
        }
        
        // Handling overlaps in foundational elements S_1 or S_2
        if (p > 0) {
            if (k == 1) {
                ans += prefX[p][c];
            } else if (k == 2) {
                ans += prefY[p][c];
            }
        }
        
        return ans;
    };

    // Answer incoming queries
    while (Q--) {
        long long L, R;
        char C;
        cin >> L >> R >> C;
        
        int c_idx = C - 'a';
        long long ans = get_count(R, c_idx) - get_count(L - 1, c_idx);
        cout << ans << "\n";
    }

    return 0;
}