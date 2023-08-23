class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        int sum =nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum<0 && nums[i]>sum){
                sum = nums[i];
            }else if(sum >= 0){
                sum = sum + nums[i];
            }

            if(max<sum){
                max = sum;
            }
            cout<<sum<<endl;
        }

        return max;
    }
};