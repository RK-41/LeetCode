class RandomizedSet {
    // 16.01.24 potd
    unordered_map<int,int> um;
    vector<int> v;
public:
    RandomizedSet() { 
    }
    
    bool search(int val) {
        if(um.find(val)!=um.end())
            return true;

        return false;
    }

    bool insert(int val) {
        if(search(val))
            return false;

        v.push_back(val);
        um[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val))    
            return false;

        auto it=um.find(val);
        v[it->second]=v.back();
        v.pop_back();
        um[v[it->second]]=it->second;
        um.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */