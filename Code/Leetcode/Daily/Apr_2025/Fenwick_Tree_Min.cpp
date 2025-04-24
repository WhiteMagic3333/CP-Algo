class Fenwick {
public:
    vector<ll> tree;
    Fenwick(int n) {
        tree.assign(n + 1, LLONG_MAX);
    }

    void update(int k, ll x) {
        k++;
        while (k < tree.size()) {
            tree[k] = min(tree[k], x); 
            k += k & -k;
        }
    }

    ll query(int k) {
        ll result = LLONG_MAX;
        k++; 
        while (k > 0) {
            result = min(result, tree[k]);
            k -= k & -k;
        }
        return result;
    }
};
