class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int left{0};
        int right = nums.size()-1;
        //e.g 7 8 9 4 5 6 
        //mp :3 => beg:0 end:4 => mid:2

        //e.g. 8 9 1 3 4 
        //beg:0, end:4,mid:2 =>
        //beg:0, end:2,mid:1 =>

        //e.g 3 4 5 6 1 2
        //e.g 7 8 9 1 3 
        //e.g 1 3 7 8 9
        //e.g 2, 1
        //e.g 3,1,2

        while(left < right){   
            
            int mid =  left + (right -left)/2;

            if(nums[right] < nums[mid])
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};
