class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
    int L{0};
    int R{static_cast<int>(nums.size()-1)};

    //nums=[5 1 3]
    //target=5

    while(L< R){    
    
        //L:0, M:1, R:2 {5 , 1 , 3}
        //L:0, M:0 , R:0 {5}
        int M = L + (R-L)/2 ;

        if(M == L) {
            return nums[M] == target ? M: nums[R] == target ?  R :-1;
        };

    cout<<"nums[L]:"<<nums[L]<<" nums[M]:"<<nums[M]<<" nums[R]:"<<nums[R]<<endl;

        if(nums[M] > nums[R]){
            if(target >= nums[M] || target <= nums[R])
            {
                L = M;
            }
            else{
                R = M-1;
            }
        }
        else{
            if(target >= nums[M] && target <= nums[R])
            {
                L = M;
            }
            else{
                R = M-1;
            }
        }


        cout<<"L:"<<L<<" R:"<<R<<endl;
    };

    cout<<"L:"<<L<<endl;
    return nums[L] == target ? L:-1;

    }
};
