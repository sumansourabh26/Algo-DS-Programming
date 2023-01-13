/*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://leetcode.com/problems/lru-cache/description/
*/


#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int capacity;
    unordered_map <int, list<pair<int,int>>::iterator> mapping;
    list<pair<int,int>> data;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mapping.count(key) == 0){
            return -1;
        }
        else{
            auto itr = mapping[key];
            pair<int, int> value = *itr;
            data.erase(itr);
            data.push_back(value);
            itr =  data.end();
            mapping[key] = --itr;
            return value.second;
        }
        
    }
    
    void put(int key, int v) {

        if(mapping.count(key) == 0){
            if(mapping.size() == capacity){
                
                auto itr = data.begin();
                mapping.erase((*itr).first);
                data.erase(data.begin());

                data.push_back(make_pair(key,v));
                itr =  data.end();
                mapping[key] = (--itr);

            }
            else{
                data.push_back(make_pair(key,v));
                auto itr =  data.end();
                mapping[key] = (--itr);
            }
                        
        } 
        else{
            auto itr = mapping[key];
            pair<int, int> value = *itr;
            data.erase(itr);
            value.second = v;
            data.push_back(value);
            itr =  data.end();
            mapping[key] = --itr;
        }       
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){

} 