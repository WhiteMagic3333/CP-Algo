class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for (int &a : derived) {
            x ^= a;
        }
        return !x;
    }
};