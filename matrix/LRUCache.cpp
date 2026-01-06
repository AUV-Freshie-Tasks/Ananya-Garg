#include "LRUCache.h"

LRUCache::LRUCache(int c) {
    cap = c;
}

bool LRUCache::has(string key) {
    return mp.find(key) != mp.end();
}

LU<double> LRUCache::get(string key) {
   
    if (mp.find(key) == mp.end()) {
        cout << key << endl;
        LU<double> empty;
        return empty;
    }

    
    auto it = mp.find(key);
    order.erase(it->second.second);
    order.push_front(key);
    it->second.second = order.begin();

    return it->second.first;
}

void LRUCache::put(string key, LU<double> val) {
    
    if (mp.find(key) != mp.end()) {
        auto it = mp.find(key);
        order.erase(it->second.second);
        order.push_front(key);
        it->second = make_pair(val, order.begin());
        return;
    }

    if ((int)mp.size() >= cap) {
        string old = order.back();
        order.pop_back();
        mp.erase(old);

        cout << "Cache full. Removing oldest key: " << old << endl;
    }

  
    order.push_front(key);
    mp[key] = make_pair(val, order.begin());
}

void LRUCache::clear() {
    order.clear();
    mp.clear();
    
}