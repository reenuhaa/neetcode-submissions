class Solution {
public:
    bool isValid(string s) {

        //Achieving at timecomplexity O(N) is the GOAL!
        //Know bracket vs index --> stack  ==> contains ONLY opening brackets!
        //When a closing bracket occurs  ==>
            //It should match the latest open bracket
            //YES - pop it Else INVALID
        
        std::stack<char> open_brackets;
        bool isValid{true};

        for(auto i=0;i< s.length(); ++i){ 
            if(s[i] == '{' || s[i] == '('||s[i] == '['){
                open_brackets.push(s[i]); //O(1)
            }
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
        }

        return (!isValid || !open_brackets.empty()) ? false: true;
    }//tc: N(O(1) [FOR PUSH] || O(1)+O(1) [FOR POP]) ==> O(N) ; sc:O(N)

};
