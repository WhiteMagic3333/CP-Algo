class ProductOfNumbers {
public:
    vector<int> prod;
    int last_zero;

    ProductOfNumbers() {
        last_zero = -1;
        prod.push_back(1);
    }
    
    void add(int num) {
        prod.push_back(max(prod.back() * num, 1));
        if (num == 0) {
            last_zero = prod.size() - 1;//index
        }
    }
    
    int getProduct(int k) {
        int first_index = prod.size() - k;
        if (first_index <= last_zero) {
            return 0;
        }
        return prod.back() / prod[first_index - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */go