class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>>idx;
    vector<int>vec;
    int total = 0;

    RandomizedCollection() {
        
    }
    
    void ins(int val) {
        vec.push_back(val);
        idx[val].insert(vec.size()-1);
    }

    bool insert(int val) {
        if(idx[val].empty()) { //not present
            ins(val);
            return true;
        }
        ins(val);
        return false;
    }
    
    bool remove(int val) {
        if(idx[val].empty()) { //not present
            return false;
        }
        int ind = *idx[val].begin();
        int lastIndex = vec.size()-1;
        int lastVal = vec[lastIndex];
        swap(vec[lastIndex], vec[ind]);
        idx[val].erase(ind);
        idx[lastVal].erase(lastIndex);
        if (ind != lastIndex) idx[lastVal].insert(ind);
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
