#if 0 // o
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        list<std::array<int,26>> charFrequencies;

        //charfrequency_list
        for(auto& i:strs){
            std::array<int,26> freq{};
            for(auto j:i){
                ++freq[j - 'a'];
            }
            charFrequencies.push_back(std::move(freq));
        }

        //string_list
        std::list<string> l;
        for(auto& i: strs){
            l.push_back(std::move(i));
        }

        std::vector<std::vector<string>> anagram_sublists;
        
        anagram_sublists.reserve(strs.size());

        do{
            auto i = charFrequencies.begin();
            auto j = std::next(i);

            auto iter1{l.begin()};
            auto iter2 = std::next(iter1);

            std::vector<string> anagrams;
            anagrams.reserve(l.size());

            while(j != charFrequencies.end()){
                if(*i == *j){
                    anagrams.push_back(std::move(*iter2));
                    iter2 = l.erase(iter2);
                    j = charFrequencies.erase(j);
                }
                else{
                    ++iter2;
                    ++j; 
                }       
            }
            anagrams.push_back(std::move(*iter1));
            l.erase(iter1);
            charFrequencies.erase(i);
            anagram_sublists.push_back(std::move(anagrams));
        
        } while(!charFrequencies.empty());

        return anagram_sublists;
    }
};
#endif

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string,std::vector<string>> angrams_grouped;

        for(auto& i: strs){
            string cpy{i};
            std::sort(cpy.begin(), cpy.end()); //O(K log K)
            angrams_grouped[cpy].push_back(std::move(i)); //O(log N) + O(1)
        }//TOTAL complexity = N* (O(K log K) + O(log N) + O(1) => O(NK log K) + O(K log N)
        vector<vector<string>> res;
        
        //how reserve works here when size of each element is unknown and vary among them??
        res.reserve(angrams_grouped.size());


        for(auto& i:angrams_grouped){
            res.push_back(std::move(i.second));// O(1)
        } //TOTAL complexity = N*O(1) => O(N)
        return res;
    } //FINAL complexity = O(NK log K) + O(K log N) + O(N)
};
