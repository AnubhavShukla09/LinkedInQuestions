class RandomizedCollection {
public:
    vector<int>vec;
    unordered_map<int, unordered_set<int>>mp;
    RandomizedCollection() {   
    }
    bool insert(int val) {
        bool flag = true;
        if(mp.count(val))flag = false;
        vec.push_back(val);
        mp[val].insert(vec.size()-1);
        return flag;
    }
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int currInd = *mp[val].begin()
    }
    int getRandom() {
        int rind = rand()%vec.size();
        return vec[rind];
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
};
