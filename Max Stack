class MaxStack {
private:
    list<int> dll; // Doubly linked list to maintain stack order, Allows O(1) insert and erase using iteratorr
    map<int, vector<list<int>::iterator>> mp; // Sorted map: value -> list of iterators pointing to nodes in dll, Helps get max element quickly
public:
    MaxStack() {}
    void push(int x) {
        dll.push_back(x);                     // add to stack
        mp[x].push_back(prev(dll.end()));     // store pointer to this node
    }
    int pop() {
        int val = dll.back();                 // get top value
        mp[val].pop_back();                   // remove reference from map
        if (mp[val].empty()) mp.erase(val);   // remove key if no occurrences left
        dll.pop_back();                       // remove from stack
        return val;
    }
    int top() {
        return dll.back();
    }
    int peekMax() {
        return mp.rbegin()->first;            // last key in sorted map = max
    }
    int popMax() {
        int maxVal = mp.rbegin()->first;      // get max value
        auto node = mp[maxVal].back();        // get latest occurrence
        dll.erase(node);                      // remove from DLL in O(1)
        mp[maxVal].pop_back();                // update map
        if (mp[maxVal].empty()) mp.erase(maxVal);
        return maxVal;
    }
};
TC - O()
