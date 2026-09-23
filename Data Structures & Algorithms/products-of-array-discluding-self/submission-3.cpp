class Solution {
public:

vector<int> productExceptSelf(vector<int>& nums) {
#if 0
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
#endif

    if(nums.size() < 2) return nums;

    if(nums.size() == 2){
        std::swap(nums[0],nums[1]);
        return nums;
    }
    
    vector<int> pref_products;
    pref_products.resize(nums.size(),1);

    vector<int> suf_products;
    suf_products.resize(nums.size(),1);
    
    int i{1};
    for(; i< nums.size(); ++i){

        //pref_products[0] = 1;
        //pref_products[1] = nums[0];
        //pref_products[2] = pref_products[1]*num[1];
        //pref_products[3] = pref_products[2]*num[2];
        pref_products[i] =  pref_products[i-1] * nums[i-1];
    }

    i = nums.size()-2;
    for(;i>=0; --i){
        suf_products[i] = suf_products[i+1] * nums[i+1];
    }
    
    for(int i = 0 ;i < nums.size(); ++i){
        nums[i] = pref_products[i] * suf_products[i];
    }
    
    return nums;
    }
};