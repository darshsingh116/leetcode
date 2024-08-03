class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        if(n==2){return max(nums[0],nums[1]);}
        if(n==3){return max(max(nums[0],nums[1]),nums[2]);}
// x 0 x 0 has 0
// 0 x 0 0 has 1
// 0 0 x 0 has none
        // int dp[3][4] = {0};
        vector<vector<int>> dp(3,vector<int>(4,0));
        //for has 0
        dp[0][0] = nums[0];
        dp[0][2] = nums[2]+nums[0];
        //for has 1
        dp[1][1] = nums[1];
        //for has none do nothing
        dp[2][2] = nums[2];

        // int temp;
        for(int i=3;i<n;i++){
            //for has 1
            dp[0][3] = max(dp[0][0],dp[0][1])+nums[i];
            dp[0].erase(dp[0].begin());
            dp[0].push_back(0);

            //for has 2
            dp[1][3] = max(dp[1][0],dp[1][1])+nums[i];
            dp[1].erase(dp[1].begin());
            dp[1].push_back(0);

            //for has none
            dp[2][3] = max(dp[2][0],dp[2][1])+nums[i];
            dp[2].erase(dp[2].begin());
            dp[2].push_back(0);
        }

        int ans;
        //for has 1
        ans= dp[0][2]-min(nums[n-1],nums[0]);
        ans = max(ans , dp[0][1]);

        //for has 2
        ans = max(ans,max(dp[1][2],dp[1][1]));

        //for has none
        ans= max(ans,max(dp[2][2],dp[2][1]));

        return ans;
    }
};