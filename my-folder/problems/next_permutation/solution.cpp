class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        bool ismax = true;
        int n = nums.size();
        int x = n-1;
        for(int i = (n-1); i>0;i--){
            if(nums[i]>nums[i-1]){
                ismax = false;
                x = i-1;
                break;
            }
        }
        int y=n-1;
        for(int i=n-1 ; i>x;i--){
            if(nums[i]>nums[x]){
                y=i;
                break;
            }
        }

        if(ismax){
            reverse(nums.begin(),nums.end());
        }else{
            int temp = nums[x];
            nums[x]=nums[y];
            nums[y] = temp;
            reverse(nums.begin()+x+1,nums.end());
        }

        return nums;
    }
};