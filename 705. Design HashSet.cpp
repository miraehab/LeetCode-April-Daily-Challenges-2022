class MyHashSet {
    vector<bool> tmp;
public:
    MyHashSet() {
        tmp = vector<bool>(1e6 + 1, false);
    }
    
    void add(int key) {
        tmp[key] = true;
    }
    
    void remove(int key) {
        tmp[key] = false;
    }
    
    bool contains(int key) {
        return tmp[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */