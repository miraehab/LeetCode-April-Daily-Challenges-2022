class MyHashMap {
public:
    vector<list<pair<int,int>>> m_data;
    MyHashMap() {
        m_data.resize(100000);
    }
    
    void put(int key, int value) {
        auto &list = m_data[key % 100000];
        for (auto & val : list) {
            if (val.first == key) {
                val.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }
    
    int get(int key) {
        const auto &list = m_data[key % 100000];
        if (list.empty()) {
            return -1;
        }
        for (const auto & val : list) {
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        auto &list = m_data[key % 100000];
        list.remove_if([key](auto n) { return n.first == key; });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */