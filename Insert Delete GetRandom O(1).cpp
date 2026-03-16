class RandomizedSet {
public:
    vector<int>vec;
    unordered_map<int, int>vi;
    RandomizedSet() {
    }
    bool insert(int val) {
        if(vi.count(val))return false;
        vec.push_back(val);
        vi[val] = vec.size()-1;
        return true;
    }
    bool remove(int val) {
        if(!vi.count(val))return false;
        int lastInd = vec.size()-1;
        int currInd = vi[val];
        if(lastInd==currInd) {
            vec.pop_back();
            vi.erase(val);
            return true;
        }
        int lastVal = vec[lastInd];
        swap(vec[currInd], vec[lastInd]);
        vi[lastVal] = currInd;
        vec.pop_back();
        vi.erase(val);
        return true;
    }
    int getRandom() {
        int rind = rand()%vec.size();
        return vec[rind];
    }
};
