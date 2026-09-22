class Solution {
public:
   string encode(vector<string>& strs) {
        ostringstream ss;
        for(auto& i:strs){
            ss << i.length()<< '#' << i;
        }
        cout<<"encoded str:"<<ss.str()<<endl;
        return ss.str();
    }

    vector<string> decode(string s) {
        istringstream ss{s};
        int len;
        char delimiter{};

        std::vector<string> strings;
        while(1)
        {
            ss >> len;
            ss >> delimiter;

            //cout<<"len:"<<len<<" delimiter:"<<delimiter<<endl;
            
            if(ss.fail()){
                return strings;
            }

            std::string s;
            s.resize(len);

            int i{0};
            while(i < len){
                s[i++] = ss.get();
            }
            
            //cout<<"reconstructed string:"<<s<<endl;
            
            strings.push_back(std::move(s));
        }

        return strings;
    }
};
