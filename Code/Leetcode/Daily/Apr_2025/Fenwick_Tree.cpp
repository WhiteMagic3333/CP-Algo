class Fenwick {
public:
    vector<ll> tree;
    Fenwick(int n) {
        tree.assign(n + 1, 0);
    }
    
    void update(int k, int x) {
        k++;
        while (k < tree.size()) {
            tree[k] += x;
            k += k & -k;  
        }
    }
    
    ll query(int k) {
        ll total = 0;
        k++;
        while (k > 0) {
            total += tree[k];
            k -= k & -k;
        }
        return total;
    }
};