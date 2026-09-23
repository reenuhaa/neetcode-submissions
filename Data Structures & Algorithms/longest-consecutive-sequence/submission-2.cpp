class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

    std::unordered_set<int> s;
    
    s.insert(nums.begin(), nums.end());
    
    int max_conseq_len{0};
    
    bool isNextFound{false};
    bool isPrevFound{false};
    
#if 0    
    for(auto i:s){ //O(N)
    //O(N^2 COMPLEXITY)       
        int next_consequtive_nums{1};
        int prev_consequtive_nums{1};
        int incr{1};
        int decr{-1};
        
        while(1) //o(N)
        {
            isNextFound = s.find(i + incr++) != s.end();  //O(1)
            if(isNextFound){
                ++next_consequtive_nums;
            }
            else {
                break;
            }
        };
        
        while(1) //O(N)
        {
            isPrevFound = s.find(i+ decr--) != s.end(); 
            if(isPrevFound){
                ++prev_consequtive_nums;
            }
            else {
                break;
            }
        };
        
        auto conseq_len = next_consequtive_nums+prev_consequtive_nums -1;
        
        cout<<"For num:"<<i<<" , conseq_len:"<<conseq_len<<endl;
        
        max_conseq_len = std::max(conseq_len , max_conseq_len);
    } //tc:O(N)*[2(O(N) * O(1)] ==> 2O(N) * O(N) => 2O(N^2) 
#endif

    for(auto i:s){
        //i should be the start of sequence;
        if(s.find(i-1) == s.end()){
                int incr{1};
                bool nextFound{false};
                int conseq_len{1};
                while(1){
                    if(s.find(i + incr++) != s.end()) {
                        ++conseq_len;
                    }
                    else{
                        break;
                    }
                };
            max_conseq_len = std::max(max_conseq_len,conseq_len);
        }
    }
    
    return max_conseq_len;
    }
};