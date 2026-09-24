class Solution {
public:
    bool isPalindrome(string s) {
        
        cout<<"s.length():"<<s.length()<<endl;
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
        for(int i=0; i< newLen/2 ;){
            if(tolower(s[i++]) != tolower(s[j--])){
                return false;
            }
        }
        return true;
    }
};
