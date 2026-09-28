class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.empty()) return 0;

        //Window - All Unique characters
        int j{0};
        int longestSubStrLength{};
        std::unordered_map<char,int> char_pos;
        int len{};
        int beginIndex{};
        for(;j<s.length();){
            
            auto idx = char_pos.find(s[j]);

            if(idx == char_pos.end() || idx->second < beginIndex){
                char_pos[s[j]] = j;
                ++j;
                ++len;
            }
            else{
            longestSubStrLength = std::max(longestSubStrLength, len);
            beginIndex = idx->second+1;
            len = j-idx->second;
            idx->second = j;
            ++j;
            }
        }
        return std::max(longestSubStrLength,len);
    }
};
