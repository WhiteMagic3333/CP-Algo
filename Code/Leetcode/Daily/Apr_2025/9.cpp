#include <csignal>
class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        bitset<101> vis;
        int ans = 0;
        for (int i : arr) {
            if (i < k) {
                return -1;
            } else if (i > k) {
                ans += !vis[i];
                vis[i] = true;
            }
        }
        return ans;
    }
};

start = 10
end = 10^6
s = 11
limit = 3

1 2 3

easily can get ans for nums having len (3 -> 6)


2 digit and 7 digit skip

for 3dig   4 dig

      3 + 12 + 48

        lim * (lim + 1) ^ (curr_digits_size - s.length())

        _ 1 1

   _  _  _ 1 1


if we can get answer from 0 -> x using fun
then using that
ans = fun(end) - fun(start - 1)

if (start <= (int)s) {
    fun(start) = 0
}




