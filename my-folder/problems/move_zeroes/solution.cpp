class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int freq = 0;
        int len = nums.size();
        for(int i=0;i<len;i++){
            nums[i-freq]=nums[i];
            if(nums[i]==0){
                freq++;
            }
            
        }
        for(int i=(len-freq);i<len;i++){
            nums[i]=0;
        }
    }
};