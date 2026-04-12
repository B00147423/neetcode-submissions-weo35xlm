class MyHashSet {
public:

    MyHashSet() {
        
    }
    
    void add(int key) {
        mp[key] = true;
    }
    
    void remove(int key) {
        mp.erase(key);
    }
    
    bool contains(int key) {
        return mp.count(key);
    }

private:
    unordered_map<int, bool> mp; 
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */