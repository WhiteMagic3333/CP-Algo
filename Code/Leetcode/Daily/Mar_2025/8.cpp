class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whites = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                whites++;
            }
        }
        int ans = whites;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') {
                whites++;
            }
            if (blocks[i - k] == 'W') {
                whites--;
            }
            ans = min(ans, whites);
        }
        return ans;
    }
};