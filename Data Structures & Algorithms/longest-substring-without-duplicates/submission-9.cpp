class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.empty()) return 0;

        //Window - All Unique characters
        int right{0};
        
        int longestSubStrLength{};
        int currentLength{};
        
        //important learning - Constraint mentions "Printable ASCII table"
        //Standard Ascii table : 128 elements: 0 to 127 value ==> Array of size:128  needed

        //Printable Ascii table: 32 - 126 : 95 elements 
        //Alpha numeric: 48 - 57 ; 65-90 ; 97 -122 
        //So all these can be represented by Array of Size:127! 
        std::array<int,127> char_pos;
        //important learning - use fill!!!! Giving in initializer list
        //e.g std::array<int,127> char_pos{-1} will initialize only the 0th index!
        char_pos.fill(-1); 

        int left{};

        for(;right<s.length();){
            auto idx = char_pos[s[right]]; //avg O(1) => N* O(1) => O(N)
            if(idx == -1 || idx < left){
                char_pos[s[right]] = right;
                ++right;
                ++currentLength;
            }
            else{
            longestSubStrLength = std::max(longestSubStrLength, currentLength);
            
            //Exclude the duplicate and set the begin, currentLength of current string
            left = idx + 1;
            currentLength = right - idx;
            
            //update the latest position 
            char_pos[s[right]] = right;
            
            //process with current string
            ++right;
            }
        }
        return std::max(longestSubStrLength,currentLength);
    } //TC: O(N), space Complexity : O(1)
};
