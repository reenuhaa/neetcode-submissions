class Solution {
public:

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prod_resut_1;
    prod_resut_1.resize(nums.size());
    
    //O(N)
    auto all_product = std::accumulate(nums.begin(),nums.end(),1,[](auto n1, auto n2){
            if(n1 != 0 && n2 != 0) {
                return n1*n2;
            }
            else if(n1 != 0) {
                return n1;
            }
            else {
                return n2;
            }}
            );
    cout<<"\nall_product:"<<all_product<<endl;

    auto count  = std::count_if(nums.begin(),nums.end(),[](auto num){return num == 0;});
    cout<<"count:"<<count<<endl;
    
    //O(N)
    std::transform(nums.begin(),nums.end(),nums.begin(),[all_product,count](auto divide){
        if(divide == 0) {
            if(count == 1){
                return all_product;
            }
            else{
                return 0;
            }
        }
        else{
            if(count != 0){
                return 0;
            }
            else{
                return all_product/divide;
            }
        }
     }
        );
    
    return nums;
} //TC: O(N) ; SC`
};