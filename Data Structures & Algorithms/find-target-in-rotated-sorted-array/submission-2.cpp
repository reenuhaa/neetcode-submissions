class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
    int L{0};
    int R{static_cast<int>(nums.size()-1)};

    //nums=[4,5,6,7,0,1,2]
    //target=0

    while(L< R){    
    
        //L:0, M:3, R:6 {4 , 7 , 2}
        //L:4, M:5, R:6 {0 , 1 , 2}
        int M = L + (R-L)/2 ;

    cout<<"nums[L]:"<<nums[L]<<"nums[R]:"<<nums[R]<<"nums[M]:"<<nums[M]<<endl;

        if(nums[M] > nums[R]){
        if(target >= nums[M] || target <= nums[R])
        {
            if(target == nums[M]) return M;
            if(target == nums[R]) return R;

            L = M+1;
        }
        else{
            R = M-1;
        }
        }
        else{
            if(target >= nums[M] && target <= nums[R])
            {
                if(target == nums[M]) return M;
                if(target == nums[R]) return R;

                L = M+1;
            }
            else{
                R = M-1;
            }
        }


        cout<<"L:"<<L<<"R:"<<R<<endl;
    };

    cout<<"L:"<<L<<endl;
    return nums[L] == target ? L:-1;

    }
};
