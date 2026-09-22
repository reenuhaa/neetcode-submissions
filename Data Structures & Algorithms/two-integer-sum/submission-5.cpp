class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
    if(nums.size() < 2) return {};

    std::unordered_multimap<int,size_t> diffsIndex;

    
#if 0 // O(N) * O(N)  = O(N^2) complexity
    for(int i=0; i< nums.size()-1; ++i){
        for(int j =i+1; j < nums.size();++j){
            if(nums[i]+nums[j] == target) return {i,j};
        }
    } 
#else  //O(N) *( O(1) + O(1)) => O(N)* 2 O(1) =>O(2N)  = O(N) complexity
    for(size_t i=0; i< nums.size(); ++i){
        auto iter = diffsIndex.find(nums[i]); //O(1)
        if (iter != diffsIndex.end()){
            return {static_cast<int>(iter->second), static_cast<int>(i)};
        }
        diffsIndex.insert(make_pair(target-nums[i],i)); //O(1)
    }
#endif
    return {}; 
    }
};
