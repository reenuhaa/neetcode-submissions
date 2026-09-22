class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
#if 0 //misunderstood as - return elements with alteast K frequency!
        std::unordered_map<int,int> num_occurences;
        for(auto i:nums){   
            ++num_occurences[i];  //O(1)
        }//time complexity:N*O(1) = O(N)
 
        vector<int> res;
        for(auto [num,occurences] :num_occurences){
            if(occurences >= k){
                res.push_back(num);
            }
        }//time complexity:N*O(1) = O(N)
        return res;
        //final time complexity =O(N) + O(N) => O(N)
#else

        std::array<int,2001> num_occurences{};
        for(auto i:nums){   
            ++num_occurences[i + 1000];  //O(1)
        }//time complexity:N*O(1) = O(N)

        std::vector<std::pair<int,int>> vec;
        vec.reserve(2001);
        int idx{-1000};
        for(auto occ:num_occurences){
            if(occ > 0)
            {
                vec.emplace_back(std::make_pair(idx++,occ)); //O(1)}
            }else
            {
                ++idx;
            }
        }//time complexity:N*O(1) = O(N)

        vector<int> res;
        res.reserve(k);

        if(vec.size() <= k)
        {
            for(auto const& [num, freq] : vec)
            res.push_back(num);
            return res;
        }
        
        std::ranges::nth_element(vec.begin(),vec.begin()+k,vec.end(),
                                std::ranges::greater{},
                                &std::pair<int,int>::second);
    

   
    //O(K)
    std::ranges::for_each(vec.begin(),vec.begin()+k,[&res](int n){
        res.push_back(n);}, &std::pair<int,int>::first);

    return res;
#endif

    }
};
