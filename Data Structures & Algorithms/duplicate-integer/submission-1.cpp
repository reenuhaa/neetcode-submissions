#include<array>
#include <iostream>
#include <set>
using namespace std;

class Solution{
public:
bool hasDuplicate(const auto& arr){
    
    std::unordered_set<int> m;
    
    for(auto& i:arr){
       auto [iter, inserted]   =  m.insert(i);
       if(inserted == false) return true;
    }
    return false;
}
};