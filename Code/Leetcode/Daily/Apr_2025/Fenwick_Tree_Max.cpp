class Fenwick {
public:
    vector<ll> tree;
    Fenwick(int n) {
        // Initialize tree with a small value (for maximum queries)
        tree.assign(n + 1, LLONG_MIN);
    }

    // Update function for Range Maximum
    void update(int k, ll x) {
        k++;  // Move to 1-indexed position
        while (k < tree.size()) {
            tree[k] = max(tree[k], x);  // Maintain the maximum value
            k += k & -k;
        }
    }

    // Query function for Range Maximum (prefix maximum)
    ll query(int k) {
        ll result = LLONG_MIN;  // Start with a small value
        k++;  // Move to 1-indexed position
        while (k > 0) {
            result = max(result, tree[k]);
            k -= k & -k;
        }
        return result;
    }
};
