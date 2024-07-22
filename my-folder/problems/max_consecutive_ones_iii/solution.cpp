class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxans = 0;
        int count = 0;
        int i=0,j=0;
        int flipped = 0;
        while(j<nums.size()){
            if(nums[j] == 1){
                count++;
                j++;
            }else{
                if(flipped<k){
                    flipped++;
                    j++;
                    count++;
                }else{
                    if(nums[i]==0){
                        flipped--;  
                    }
                    count--;
                    i++;
                }
            }

            maxans = max(maxans,count);
        }
        return maxans;
    }
};