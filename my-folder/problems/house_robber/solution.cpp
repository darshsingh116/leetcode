using namespace std;
class Solution {    
public:
    int rob(vector<int>& nums) {       
        int n = nums.size();
        vector<int> dp(n, 0);
        int ans = 0;
        for(int i=0;i<n;i++){
            cout<<endl;
            if( i-2 < 0){
                dp[i] = nums[i];
                
            }else{
                for(int j=(i-2); (j>=0 && j>= i-3);j--){
                    
                    if(dp[j]+nums[i] > dp[i]){
                        dp[i] = nums[i] + dp[j];
                    }
                    cout<<dp[i]<< " ";
                    
                }
            }

            if(dp[i]>ans){
                        ans=dp[i];
                    }
            
            
        }

        return ans;

    }
};