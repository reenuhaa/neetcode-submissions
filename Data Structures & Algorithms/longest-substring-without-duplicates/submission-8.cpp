class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.empty()) return 0;

        //Window - All Unique characters
        int j{0};
        
        int longestSubStrLength{};
        int len{};
        
        std::array<int,127> char_pos;
        char_pos.fill(-1);

        int beginIndex{};

        for(;j<s.length();){
            auto idx = char_pos[s[j]]; //avg O(1) => N* O(1) => O(N)
            if(idx == -1 || idx < beginIndex){
                char_pos[s[j]] = j;
                ++j;
                ++len;
            }
            else{
            longestSubStrLength = std::max(longestSubStrLength, len);
            
            //Exclude the duplicate and set the begin, len of current string
            beginIndex = idx + 1;
            len = j - idx;
            
            //update the latest position 
            char_pos[s[j]] = j;
            
            //process with current string
            ++j;
            }
        }
        return std::max(longestSubStrLength,len);
    } //TC: O(N), space Complexity : O(N)
};
