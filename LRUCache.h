#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <unordered_map>
#include <list>
#include <string>
#include <iostream>
#include "LU.h"

using namespace std;

class LRUCache {
public:
    int cap;   
    LRUCache(int c = 5);

    bool has(string key);
    LU get(string key);    
    void put(string key, LU val);

    void clear();

private:
    list<string> order;  
    unordered_map<string, pair<LU, list<string>::iterator>> mp;
};

#endif
