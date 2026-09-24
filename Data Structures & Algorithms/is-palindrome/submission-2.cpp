class Solution {
public:

bool isPalindrome(string s) {
#if 0 
// std::rmove_if used -> but it involves "more work" of modifying the input string        
        cout<<"s.length():"<<s.length()<<endl;

        //O(N)
        auto newEnd = std::remove_if(s.begin(),s.end(),[](char ch){
            if(!((ch >=48 && ch<=57)||(ch >=65 && ch<=90)||(ch >=97 && ch<=122))){
                cout<<"ignoring ch:"<<std::boolalpha<<ch<<endl;
                return true;
            }
            return false;
        });

        auto newLen = std::distance(s.begin(),newEnd);
        cout<<"newLen:"<<newLen<<endl;
        int j = newLen-1;
        
        //O(N/2)
        for(int i=0; i< newLen/2 ;){
            if(tolower(s[i++]) != tolower(s[j--])){
                return false;
            }
        }
        return true;
    //} //TC: O(N/2 + N)=> O(3/2N)==> O(N) ; SC:O(1)
#endif
//Soln - no modification of input string
        int i{0};
        int j{static_cast<int>(s.length()-1)};

        while(i<j){
            while(!std::isalnum(s[i])){ ++i;};
            while(!std::isalnum(s[j])){ --j;};

            if(i<j)
            {
                if(std::tolower(s[i++]) != std::tolower(s[j--]))
                {
                    return false;
                }
            }
        };

        return true;
    }
};