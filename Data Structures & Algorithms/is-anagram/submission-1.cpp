#include<string>
#include<map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;

        std::unordered_map<char,int> charOccurences;

        //N*O(1)
        for(auto i=0; i< s.length() ; ++i){
            ++charOccurences[s[i]]; 
        }

        //N*O(1)
        for(auto i=0; i< t.length() ; ++i){
            auto res = --charOccurences[t[i]];
            if(res < 0) return false; 
        }

        return true;
    }
};
