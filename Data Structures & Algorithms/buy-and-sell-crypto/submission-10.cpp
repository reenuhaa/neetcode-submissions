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
#if 0 //O(N^2) complexity
        for(int i{0}; i< prices.size();++i){
            for(int j{i+1}; j< prices.size();++j){
maxProfit = (prices[j] - prices[i]) > 0 ? std::max(maxProfit,(prices[j]-prices[i])):maxProfit;
            }
        }
#endif
#if 0  //Copilot says it is error Prone!! 
        for(int i{0}; i< prices.size()-1;){
            cout<<"Finding max profit for buying index:"<<i<<endl;
            int j{i+1};
            int lowestPricePointIdx{-1};
            int lowestPricePoint{0};
            int highestPricePointIndex{-1};;
            for(; j< prices.size();++j){
                if((prices[j] - prices[i]) < lowestPricePoint){
                lowestPricePointIdx = j;
                lowestPricePoint = prices[j] - prices[i];
                cout<<"lowestPricePointIdx:"<<lowestPricePointIdx
                <<"lowestPricePoint:"<<lowestPricePoint<<endl;
                }
                else if(prices[j]-prices[i] > maxProfit){
                    highestPricePointIndex = j;
                    cout<<"highestPricePointIndex:"<<highestPricePointIndex<<endl;
                    maxProfit = prices[j]-prices[i];
                }
            }
if(lowestPricePointIdx > i && lowestPricePointIdx < highestPricePointIndex){
                i = lowestPricePointIdx ;
            }
            else{
                ++i;
            }
            cout<<"maxProfit:"<<maxProfit<<endl;
        }
        return maxProfit;
#endif
    int minPrice{prices[0]};
    for(int i = 0; i< prices.size() ; ++i){
        //Find MinPrice so far! ==> buying price
        minPrice = std::min(minPrice, prices[i]);
        
        //Check maxProfit So far, considering buying at minPrice!
        maxProfit = std::max(maxProfit, prices[i]-minPrice);
    }
    return maxProfit;
    }
};