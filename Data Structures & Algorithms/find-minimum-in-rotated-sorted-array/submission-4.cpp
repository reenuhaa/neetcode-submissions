class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int beginPos{0};
        int endPos = nums.size()-1;
        int midPos{-1};
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

        while(beginPos < endPos){   
            
            midPos =  beginPos + (endPos -beginPos)/2;

            if(nums[endPos] < nums[midPos])
            {
                beginPos = midPos+1;
            }
            else
            {
                endPos = midPos;
            }
        }
        return nums[beginPos];
    }
};
