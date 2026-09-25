class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area{0};
#if 0
        //Need to find  w,h  such that are is max! 
        //e.g w:2 h:100 ==> 200 ; w:100 h:2 ==>200

        std::vector<int> heightPerWidth;
        heightPerWidth.resize(heights.size());

        //Find 2 Height  which are tall and wide! - 2 pointer 
        int max_height{0};
        int possible_same_width_cnt{1};
        int width = heights.size()-1;
        while(width > 0){  
            int l{0};
            int r{width};

            while(r < heights.size()){
            heightPerWidth[r-l] = max(heightPerWidth[r-l],min(heights[l],heights[r]));
            ++l;
            ++r;
            };
            
            --width;
        }

        int i{0};

        for(auto height:heightPerWidth){
            max_area = std::max(max_area, height * i++);
        }
#endif
        int l{0};
        int r{static_cast<int>(heights.size()-1)};
        while(l<r){
            max_area = std::max(max_area, (r-l)*std::min(heights[l],heights[r]));
            
            if(heights[l] < heights[r])
            {
                ++l;
            }
            else{
                --r;
            }
        };

        cout<<"max_area:"<<max_area<<endl;
        return max_area;
    }

};
