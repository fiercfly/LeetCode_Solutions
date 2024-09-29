class AllOne {
public:
    unordered_map<string, int> freq;
    set<pair<int, string>> set;
    AllOne() {
        
    }
    
    void inc(string key) {
        set.erase({freq[key], key});
        freq[key]++;
        set.insert({freq[key], key});
    }
    
    void dec(string key) {
        set.erase({freq[key], key});
        freq[key]--;
        if(freq[key] != 0)
            set.insert({freq[key], key});
    }
    
    string getMaxKey() {
        if(set.empty()) return "";
        auto it = set.end();
        --(it);
        return it->second;
    }
    
    string getMinKey() {
        if(set.empty()) return "";
        auto it = set.begin();
        return it->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */