class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //use set to sort it + lookup better than vector!

        std::vector<std::vector<int>> res;

        if(nums.empty()) return res;


        std::sort(nums.begin(), nums.end());

        if(nums[0] > 0){
            return res;
        }


        if(nums[0] == 0){
            if(nums[1] == 0 && nums[2] == 0){
                res.emplace_back(std::vector<int>(3,0));
            }
            return res;
        }

        for(int i=0; (i<nums.size() && nums[i]<= 0); ++i){

            if(i>0 && (nums[i] == nums[i-1])){
                continue;
            }

           int j = i+1, k= nums.size()-1;
           while(j<k){


                if((nums[j] + nums[k] + nums[i]) < 0){
                    ++j;
                }
                else if((nums[j] + nums[k] + nums[i]) > 0){
                   --k;
                }
                else{
                res.emplace_back(std::vector({nums[i],nums[j],nums[k]}));

                while(j<k && nums[j] == nums[j+1]){ ++j;}
                while(j<k && nums[k] == nums[k-1]){--k;}

                    ++j;
                    --k;
                }
           }    
        }
        return res;
    }
};
