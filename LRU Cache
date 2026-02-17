class LRUCache {
public:
    unordered_map<int, pair<int, list<int>::iterator>> mp; // key to {val, address in cache}
    list<int> cache; // front is the latest entry, stores the key
    int capacity;
    LRUCache(int capacity) { this->capacity = capacity; }
    void makeMRU(int key, int val) {
        cache.push_front(key);
        mp[key] = {val, cache.begin()};
    }
    int get(int key) {
        if (!mp.count(key))
            return -1;
        int val = mp[key].first;
        cache.erase(mp[key].second);
        makeMRU(key, val);
        return val;
    }
    void put(int key, int value) {
        if (mp.count(key)) {
            cache.erase(mp[key].second);
            makeMRU(key, value);
        } else {
            if (cache.size() == capacity) {
                int keyToDelete = cache.back();
                cache.pop_back();
                mp.erase(keyToDelete);
            }
            makeMRU(key, value); 
        }
    }
};
