class Solution {
public:
    int myfind(vector<int>& nums){
        int ans = nums[0];
        int prod = 1;
        int backup;
        int neg;
        bool hadneg = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0){
                if(hadneg){
                    prod = backup*prod*neg*nums[i];
                    hadneg = false;
                    cout<<"hadneg at"<<prod<<endl;
                    if(prod > ans){
                        ans = prod;
                    }
                }else{
                    neg = nums[i];
                    backup=prod;
                    prod = 1;
                    hadneg=true;
                }              
            }else if(nums[i] == 0){
                prod = 1;
                hadneg = false;
                if(0 > ans){
                ans = 0;
            }
            }else{
                prod *= nums[i];
                if(prod > ans){
                ans = prod;
            }
            }
            cout<<prod<<endl;

            
            

        }
        return ans;
    }
    int maxProduct(vector<int>& nums) {
        int a,b;
        a = myfind(nums);
        reverse(nums.begin(), nums.end());
        b = myfind(nums);
        return max(a,b);
    }
};