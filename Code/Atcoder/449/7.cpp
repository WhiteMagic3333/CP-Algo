#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(vector<int> structures) {
    int n = structures.size();
    if (n == 0) return 0;

    long long max_h_asc = -2e18; // Use a very small value
    for (int i = 0; i < n; ++i) {
        max_h_asc = max(max_h_asc, (long long)structures[i] - i);
    }

    long long cost_asc = 0;
    for (int i = 0; i < n; ++i) {
        cost_asc += (max_h_asc + i) - structures[i];
    }

    long long max_h_desc = -2e18;
    for (int i = 0; i < n; ++i) {
        max_h_desc = max(max_h_desc, (long long)structures[i] + i);
    }

    long long cost_desc = 0;
    for (int i = 0; i < n; ++i) {
        cost_desc += (max_h_desc - i) - structures[i];
    }

    return min(cost_asc, cost_desc);
}