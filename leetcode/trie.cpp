/*
*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem : https://leetcode.com/problems/implement-trie-prefix-tree/
*/

#include <bits/stdc++.h>
using namespace std;


class Trie {

    bool present[27];
    Trie* children[26];
public:
    Trie() {
        memset(present, false, sizeof(present));
        memset(children, false, sizeof(children));
    }

    void insert(string word) {
        if (word[0] == '\0') {
            present[26] = true;
            return;
        }

        if (!present[word[0] - 'a']) {
            present[word[0] - 'a'] = true;
            children[word[0] - 'a'] = new Trie();
        }
        children[word[0] - 'a']->insert(word.substr(1));
    }

    bool search(string word) {
        //cout << word << endl;
        if (word[0] == '\0') return (present[26]);

        if (!present[word[0] - 'a'])  return false;        
        else return children[word[0] - 'a']->search(word.substr(1));    
    }

    bool startsWith(string word) {
        if (word[0] == '\0') return (true);

        if (!present[word[0] - 'a']) return false;
        else return children[word[0] - 'a']->startsWith(word.substr(1));

    }
};