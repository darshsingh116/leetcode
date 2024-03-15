class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        int sum=nums[0];
        int len=nums.size();
        for(int i=1;i<len;i++){            
            if(sum>=0){
                sum=sum+nums[i];
            }else{
                sum=nums[i];
            }
            if(max<sum){max=sum;}
        }
        return max;
    }
};