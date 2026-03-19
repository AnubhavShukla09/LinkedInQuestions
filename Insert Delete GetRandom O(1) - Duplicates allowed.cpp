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
// TC -
// RandomizedCollection() : O(1)
// insert(val)            : O(1) average
// remove(val)            : O(1) average
// getRandom()            : O(1)

// SC - O(n)
