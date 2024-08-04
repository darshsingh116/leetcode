class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long mod = 1e9+7;
        vector<int> prefix,ans;
        prefix.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            prefix.push_back(nums[i]+prefix[i-1]);
        }
        
        for(int l=1;l<=nums.size();l++){
            for(int i=0;i<nums.size()+1-l;i++){
                if(i==0){
                    ans.push_back(prefix[l-1]);
                }else{
                    ans.push_back(prefix[i+l-1]-prefix[i-1]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        long sum=0;
        
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i]<<" ";
        // }
        for(int i=left-1;i<right;i++){
            sum = (sum+ans[i])%mod;
        }
        return sum;
    }
};