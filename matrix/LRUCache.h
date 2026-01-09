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
    LU<double> get(string key);
    void put(string key, LU<double> val);

    unordered_map<string, pair<LU<double>, list<string>::iterator>> mp;

    void clear();

private:
    list<string> order;  
    	
};

#endif
