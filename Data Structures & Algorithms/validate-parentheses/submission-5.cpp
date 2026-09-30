class Solution {
public:
    bool isValid(string s) {

        //Achieving at timecomplexity O(N) is the GOAL!
        //Know bracket vs index --> stack  ==> contains ONLY opening brackets!
        //When a closing bracket occurs  ==>
            //It should match the latest open bracket
            //YES - pop it Else INVALID
#if 0 // IMPORTANT learning - to simplify  - Eliminate usage of map!        
        std::stack<char> open_brackets;
        bool isValid{true};

        //IMPORTANT learning - create matching map to use it 
        std::unordered_map<char, char> matching{{'}','{'},{']','['},{')','('}};

        for(auto i=0;i< s.length(); ++i){ 
            if(s[i] == '{' || s[i] == '('||s[i] == '['){
                open_brackets.push(s[i]); //O(1)
            }
            else if(s[i] == ')' || s[i] == '}'||s[i] == ']')
            {
                if(!open_brackets.empty() && open_brackets.top() == matching[s[i]]){ //O(1)
                    open_brackets.pop(); //O(1)
                }
                else{
                    isValid = false;
                    break;
                }
            }
#if 0   //learning - use matching map instead for multiple else if
            else if(s[i] == ')'){
                if(!open_brackets.empty() && open_brackets.top() == '('){ //O(1)
                    open_brackets.pop(); //O(1)
                }
                else{
                    isValid = false;
                    break;
                }
            }
            else if(s[i] == '}'){
                if(!open_brackets.empty() && open_brackets.top() == '{'){ 
                    open_brackets.pop();
                }
                else{
                    isValid = false;
                    break;
                }
            }
            else if(s[i] == ']'){
                if(!open_brackets.empty() && open_brackets.top() == '['){
                    open_brackets.pop();
                }
                else{
                    isValid = false;
                    break;
                }
            }
#endif
        }

        return (!isValid || !open_brackets.empty()) ? false: true;
#endif
        std::stack<char> close_brackets;
        for(auto i=0; i< s.length() ; ++i){
            switch(s[i]){
                    case '(':
                        close_brackets.push(')');
                        break;
                    case '{':
                        close_brackets.push('}');
                        break;
                    case '[':
                        close_brackets.push(']');
                        break;
                    default: //any closing bracket OR NON-bracket char
                        if(close_brackets.empty() || close_brackets.top() !=s[i])
                        {
                            return false;
                        }
                        
                        close_brackets.pop();
                        break;
                }
            }
            return close_brackets.empty();

    }//tc: N(O(1) [FOR PUSH] || O(1)+O(1) [FOR POP]) ==> O(N) ; sc:O(N)

};
