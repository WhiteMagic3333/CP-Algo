#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <deque>
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
 
void sieve(ll n)
{
    prime.resize(n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (prime[i] && i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}
 
template<typename T>
std::istream& operator>>(std::istream&in, std::vector<T>& v) {
    for (T& x : v)
        in >> x;
    return in;
}
 
template<typename T>
std::ostream& operator<<(std::ostream&out, std::vector<T>& v) {
    for (const T& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
    return out;
}
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_ones = 0;
    int total_wildcards = 0;
    
    vector<int> pre_ones(n + 1, 0);
    vector<int> pre_zeroes(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        pre_ones[i + 1] = pre_ones[i] + (s[i] == '1');
        pre_zeroes[i + 1] = pre_zeroes[i] + (s[i] == '0');
        total_ones += (s[i] == '1');
        total_wildcards += (s[i] == '?');
    }

    int min_swaps = n;
    
    for (int target_len = total_ones; target_len <= total_ones + total_wildcards; ++target_len) {
        if (target_len == 0) {
            min_swaps = 0;
            continue;
        }
        
        for (int i = 0; i <= n - target_len; ++i) {
            int ones_inside = pre_ones[i + target_len] - pre_ones[i];
            int zeros_inside = pre_zeroes[i + target_len] - pre_zeroes[i];
            int ones_outside = total_ones - ones_inside;
            
            min_swaps = min(min_swaps, max(ones_outside, zeros_inside));
        }
    }


    int max_swaps = 0;
    int low = 0, high = n / 2;
    
    while (low <= high) {
        int test_swaps = low + (high - low) / 2;
        bool is_possible = false;

        for (int target_ones = total_ones; target_ones <= total_ones + total_wildcards; ++target_ones) {
            int max_allowed_in_window = target_ones - test_swaps;
            if (max_allowed_in_window < 0) continue;
            if (target_ones == 0) { is_possible = true; break; }

            int num_windows = n - target_ones + 1;
            bool valid_initial_state = true;
            
            for (int w = 0; w < num_windows; ++w) {
                int ones_already_here = pre_ones[w + target_ones] - pre_ones[w];
                if (ones_already_here > max_allowed_in_window) {
                    valid_initial_state = false;
                    break;
                }
            }
            if (!valid_initial_state) continue;

            int ones_placed = total_ones;
            vector<int> pref_placed(n + 1, 0);
            
            vector<int> window_limit(num_windows, 0); 
            deque<int> active_windows;

            for (int i = 0; i < n; ++i) {
                pref_placed[i + 1] = pref_placed[i];
                
                if (i < num_windows) {
                    int fixed_ones = pre_ones[i + target_ones] - pre_ones[i];
                    window_limit[i] = max_allowed_in_window - fixed_ones + pref_placed[i];
                    
                    while (!active_windows.empty() && window_limit[active_windows.back()] >= window_limit[i]) {
                        active_windows.pop_back();
                    }
                    active_windows.push_back(i);
                }

                while (!active_windows.empty() && active_windows.front() < i - target_ones + 1) {
                    active_windows.pop_front();
                }

                if (s[i] == '?') {
                    int tightest_limit = active_windows.empty() ? 1e9 : window_limit[active_windows.front()];
                    
                    if (pref_placed[i] + 1 <= tightest_limit) {
                        pref_placed[i + 1] = pref_placed[i] + 1;
                        ones_placed++;
                    }
                }
            }

            if (ones_placed >= target_ones) {
                is_possible = true;
                break;
            }
        }

        if (is_possible) {
            max_swaps = test_swaps;
            low = test_swaps + 1;
        } else {
            high = test_swaps - 1; 
        }
    }

    cout << min_swaps << " " << max_swaps;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}