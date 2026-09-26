class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //For each element find the diff against rest of following indices;
        //Given 100 days Price-->  Need to Sell within 100 days of purchase
        //Buying on day0 sell any day 1 to 99 days
        //Buying on day1 sell any day 2 to 99 days
        //...
        //Buying on day98 sell day99
        
        int maxProfit{};
        for(int i{0}; i< prices.size();++i){
            for(int j{i+1}; j< prices.size();++j){
maxProfit = (prices[j] - prices[i]) > 0 ? std::max(maxProfit,(prices[j]-prices[i])):maxProfit;
            }
        }
        return maxProfit;
    }
};
