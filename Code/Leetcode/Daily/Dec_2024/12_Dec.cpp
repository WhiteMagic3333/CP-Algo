class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        multiset<int, greater<int>> s;
        for (auto gift : gifts) { //n (nlogn for all)
            s.insert(gift); //log(n)
        }
        while(k--) {
            auto l_ptr = s.begin(); //O(1);
            int largest = *l_ptr;
            s.erase(l_ptr); //O(logn)
            int sq_rt = (int)sqrt(largest);
            s.insert(sq_rt);
        }
        long long ans = 0;
        for (auto &cur : s) {
            ans += cur;
        }
        return ans;
    }
};