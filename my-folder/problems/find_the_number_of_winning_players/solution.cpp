class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> dp(n,vector<int>(11,0));
        vector<int> winner(n,0);
        for(auto x:pick){
            dp[x[0]][x[1]]++;
            if(dp[x[0]][x[1]] > x[0]){
                winner[x[0]]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(winner[i]){ans++;}
        }
        return ans;
    }
};