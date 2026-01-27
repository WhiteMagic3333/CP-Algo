#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    cout << grid[0][0];

    vector<pair<int, int>> level;
    level.emplace_back(0, 0);

    for (int i = 0; i < 2 * n - 2; i++) {
        vector<pair<int, int>> next_level;
        char min_letter = 'Z' + 1;

        auto update_next_level = [&](int y, int x) {
            if (y < n && x < n) {
                char letter = grid[y][x];
                if (letter < min_letter) {
                    next_level.clear();
                    min_letter = letter;
                }
                if (letter == min_letter) {
                    next_level.emplace_back(y, x);
                }
            }
        };

        for (auto [y, x] : level) {
            update_next_level(y + 1, x);
            update_next_level(y, x + 1);
        }

        cout << min_letter;

        level = next_level;
        level.erase(unique(level.begin(), level.end()), level.end());
    }
    cout << "\n";
}