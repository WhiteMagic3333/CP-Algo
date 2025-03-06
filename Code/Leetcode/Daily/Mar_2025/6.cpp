class Solution {
public://Not my solution :(
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // Get XOR of grid and (1-n)
        int xorSum = 0, n = grid[0].size()*grid[0].size();
        for(vector<int>& vec : grid) for(int i : vec) xorSum ^= i;
        for(int i = 1; i <= n; ++i) xorSum ^= i;

        // Get first bit in xorSum
        int seperator = 1;
        while(!(seperator&xorSum)) seperator <<= 1;

        // get both nums
        int a = 0, b = 0;
        for(vector<int>& vec : grid) for(int i : vec){
            if(seperator&i) a ^= i;
            else b ^= i;
        }
        for(int i = 1; i <= n; ++i){
            if(seperator&i) a ^= i;
            else b ^= i;
        }

        // check if a or b is in matrix
        for(vector<int>& vec : grid) for(int i : vec) if(i == b) return {b, a};
        
        return {a, b};
    }
};