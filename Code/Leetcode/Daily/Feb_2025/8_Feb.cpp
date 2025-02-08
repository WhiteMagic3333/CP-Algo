class NumberContainers {
public:
    unordered_map<int, int> index; //number at index
    unordered_map<int, set<int>> num;// index of number
    NumberContainers() {
        
    }
    
    void change(int idx, int number) {
        if (index[idx] != 0) {
            //remove old idx
            num[index[idx]].erase(idx);
            index[idx] = number;
            num[number].insert(idx);
        } else {
            index[idx] = number;
            num[number].insert(idx);
        }
    }
    
    int find(int number) {
        if (num[number].size()) {
            return *(num[number].begin());
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */