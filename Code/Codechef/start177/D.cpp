#include <iostream>
#include <set>
#include <vector>
using namespace std;

void solve() {
    int T;
    cin >> T;  // number of test cases
    vector<int> queries(T);
    int max_n = 0;
    
    // Read all queries and track the largest N
    for (int i = 0; i < T; i++) {
        cin >> queries[i];
        max_n = max(max_n, queries[i]);
    }
    
    // DP table to store the number of distinct (X, Y) pairs for each N
    vector<int> dp(max_n + 1);
    
    // Initialize for the base case when N = 1
    dp[1] = 1;  // Only one binary string "0" or "1", both have (X, Y) = (0, 0)
    
    // Precompute for all lengths up to max_n
    for (int n = 2; n <= max_n; ++n) {
        set<pair<int, int>> distinct_pairs;  // Set to store distinct (X, Y) pairs
        
        // Process all binary strings of length n
        for (int i = 0; i < (1 << n); ++i) {
            string S = bitset<20>(i).to_string().substr(20 - n);  // Binary string of length n
            int X = 0, Y = 0;
            
            // Count "01" and "10" subsequences
            for (int j = 0; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (S[j] == '0' && S[k] == '1') X++;
                    if (S[j] == '1' && S[k] == '0') Y++;
                }
            }
            
            // Insert (X, Y) into the set
            distinct_pairs.insert({X, Y});
        }
        
        // Store the size of the set as the result for this N
        dp[n] = distinct_pairs.size();
    }
    
    // Output the results for each test case
    for (int i = 0; i < T; ++i) {
        cout << dp[queries[i]] << endl;
    }
}

int main() {
    solve();
    return 0;
}
