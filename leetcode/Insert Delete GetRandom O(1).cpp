/*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem : https://leetcode.com/problems/insert-delete-getrandom-o1/
*/

#include <bits/stdc++.h>
using namespace std;


class RandomizedSet {
    unordered_map<int,int> position_of_values;
    vector<int> array_of_values;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(position_of_values.count(val)){
            return false;
        }else{
            array_of_values.push_back(val);
            position_of_values[val] = array_of_values.size()-1; 
            return true;            
        }
    }
    
    bool remove(int val) {
        if(position_of_values.count(val)){

            int pos = position_of_values[val];

            array_of_values[pos] = array_of_values[array_of_values.size()-1];
            array_of_values.pop_back();
            position_of_values[array_of_values[pos]] = pos;
            position_of_values.erase(val);

            return true;
        }else{
            return false;
        }
    }
    
    int getRandom() {
        return array_of_values[rand() % (array_of_values.size())];

        
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */