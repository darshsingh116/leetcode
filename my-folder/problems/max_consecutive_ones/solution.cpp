class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int ans=0,maxans=0;
        int i=0,j=0;

        while(j<n){
            if(nums[j]==1){
                ans++;
                j++;
            }else{
                maxans=max(ans,maxans);
                ans=0;
                j++;
                i=j;
            }
            
        }
        maxans=max(ans,maxans);

        return maxans;

    }
};