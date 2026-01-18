class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>:: iterator, int>> mp;
    int cap;

    LRUCache(int capacity) {
        cap=capacity;
    }

    void recUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            recUsed(key);
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key].second=value;
            recUsed(key);
        }

        else{
            dll.push_front(key);
            mp[key]={dll.begin(), value};
            cap--;
        }

        if(cap<0){
            mp.erase(dll.back());
            dll.pop_back();
            cap++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */