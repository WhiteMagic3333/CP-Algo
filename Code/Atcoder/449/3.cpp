#include <vector>
#include <algorithm>

long getMaxRequests(int bandwidth_count, int* bandwidth, int request_count, int* request, int totalBandwidth) {
    // std::vector automatically handles memory allocation and initializes all elements to 0
    std::vector<long> dp(totalBandwidth + 1, 0);
    
    // Iterate through each API endpoint
    for (int i = 0; i < bandwidth_count; i++) {
        int current_bw = bandwidth[i];
        long current_req = static_cast<long>(request[i]); // Cast to prevent overflow
        
        // Traverse the DP array backwards from totalBandwidth down to current_bw
        for (int w = totalBandwidth; w >= current_bw; w--) {
            // std::max elegantly handles the "pick vs skip" comparison
            dp[w] = std::max(dp[w], dp[w - current_bw] + current_req);
        }
    }
    
    // The maximum requests for the full capacity will be at the last index
    return dp[totalBandwidth];
}