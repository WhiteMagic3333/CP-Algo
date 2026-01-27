#include <array>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
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

void add(vector<pair<ll, ll>> &items, priority_queue<array<ll, 4>> &pq, vector<pair<ll, ll>> &rem, int group_size, ll &item_count) {
    int weight_per_item = (group_size == 6) ? 1 : (group_size == 3 ? 2 : 3);
    ll groups = (item_count / group_size);
    ll group_item_count = groups * group_size;
    ll rem_count = item_count - group_item_count;
    for (int i = items.size() - 1; rem_count > 0; i--) {
        while (rem_count) {
            rem.push_back({items[i].first, weight_per_item});
            rem_count--;
            items[i].second--;
        }
    }
    stack<pair<ll, ll>> ungrouped;
    int ungrouped_size = 0;
    for (auto &[v, k] : items) {
        if (ungrouped_size) {
            if (ungrouped_size + k < group_size) {
                ungrouped.push({v, k});
                ungrouped_size += k;
                k = 0;
                continue;
            } else {
                ll cur_item_used = group_size - ungrouped_size; 
                array<ll, 4> group = {cur_item_used * v, v, weight_per_item, 1};  
                while (ungrouped.size()) {
                    group[2] += ungrouped.top().second;
                    group[0] += ungrouped.top().first * ungrouped.top().second;
                    ungrouped.pop();
                }
                pq.push(group);
                k -= cur_item_used;
            }
        }
        if (k >= group_size) {
            ll item_used = (k / group_size) * group_size;
            pq.push({v * group_size, v * item_used, item_used});
            k -= item_used;
            ungrouped_size += item_used;
            ungrouped.push({v, k});
        }
    }
}
 
void solve()
{
    //so 6 times an item 1 has same weight as
    //3 times item 2 and
    //2 times item 3
    ll n, c;
    cin >> n >> c;
    vector<pair<ll, ll>> one, two, three; //{value, item_counts} for weight one, two, three
    vector<ll> item_count(3, 0);
    for (int i = 0; i < n; i++) {
        ll w, v, k;
        cin >> w >> v >> k;
        item_count[w % 3] += k;
        if (w == 1) {
            one.push_back({v, k});
        } else if (w == 2) {
            two.push_back({v, k});
        } else {
            three.push_back({v, k});
        }
    }
    //for one
    //sort all
    //form groups of 6 and add to priority queue, keeep the remaining in the array
    //remaining items < 6

    // similarly do for two and three
    // remaing for two < 3
    // remaining for three < 2

    // atmost 5 + 2 + 1 = 2 ^ 8 = 256 ways

    sort(one.begin(), one.end(), greater<pair<ll, ll>> ());
    sort(two.begin(), two.end(), greater<pair<ll, ll>> ());
    sort(three.begin(), three.end(), greater<pair<ll, ll>> ());
    
    //{value per group, value per weight, weight, groups}
    priority_queue<array<ll, 4>> pq;
    

    vector<pair<ll, ll>> rem; //remaining group
    add(one, pq, rem, 6, item_count[1]);
    add(two, pq, rem, 3, item_count[2]);
    add(three, pq, rem, 2, item_count[0]);

    while (pq.size() && c) {

    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}


// for weight 1
// {value_per_6, total value, item_counts}
// {60, 60, 6}
// {36, 36, 6}
// 10, 1
// 6, 3
// 4, 2

// sort priority_queue by value per 6 items, (total_weight * 6 / item_counts)


// {value_per_6, total value, item_counts}
// V  COUNT
// 10, 17
// 6, 3
// 4, 4

// {60, 120 , 12}
// 10, 5
// 6, 3
// 4, 4

// {56, 56, 6}


// 6, 2
// 4, 4

// {28, 28, 6}




// 5 + 2 + 1 = 8

//00000000 = 256