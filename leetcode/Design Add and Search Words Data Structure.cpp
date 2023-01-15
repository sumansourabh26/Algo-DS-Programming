/*
*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem : https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
*/

#include <bits/stdc++.h>
using namespace std;

class WordDictionary {

    bool present[27];
    WordDictionary* children[26];
public:
    WordDictionary() {
        memset(present, false, sizeof(present));
        memset(children, false, sizeof(children));
    }

    void addWord(string word) {
        if (word[0] == '\0') {
            present[26] = true;
            return;
        }

        if (!present[word[0] - 'a']) {
            present[word[0] - 'a'] = true;
            children[word[0] - 'a'] = new WordDictionary();
        }
        children[word[0] - 'a']->addWord(word.substr(1));
    }

    bool search(string word) {
        //cout << word << endl;
        if (word[0] == '\0') return (present[26]);

        if(word[0] == '.'){
            string substr = word.substr(1);
            for(int i = 0; i < 26; i++){
                if(present[i] && children[i]->search(substr)) return true;
            }
            return false;
        }
        else if (!present[word[0] - 'a'])  return false;        
        else return children[word[0] - 'a']->search(word.substr(1));    
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){
    WordDictionary wd = WordDictionary();
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("sad");
    cout<<wd.search("bad");
    cout<<wd.search(".ad");
}