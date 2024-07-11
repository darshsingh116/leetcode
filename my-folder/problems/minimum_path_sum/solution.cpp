using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int h = grid.size();
        int l = grid[0].size();
        vector<vector<int>> dp(h, vector<int>(l, 201));
    
        //int x = i*3+j;
        int i,j;

        for(int level = h+l-2; level>=0;level--){           
            j = min(l-1, level);
            i = level-j;
            
            while(i>=0 && i<h && j>=0 && j<l){
            cout<<"~~~"<<i<<" "<<j<<endl;
            if(j+1 == l && i+1 == h){
                dp[i][j] = grid[i][j];
            }else if(j+1<l && i+1<h){
                dp[i][j] = grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }else if(j+1==l){
                dp[i][j] = grid[i][j] + dp[i+1][j];
            }else {
                dp[i][j] = grid[i][j] + dp[i][j+1];
            }
            cout<<dp[i][j]<<endl;
            
            j=j-1;
            i = level-j;
            }
        }

        return dp[0][0];

        // for(int x=(n*n)-1 ; x>=0;x--){
        //     j = x%3;
        //     i = x/3;
        //     cout<<i<<" "<<j<<endl;
        //     if(j+1 == n && i+1 == n){
        //         dp[x] = grid[i][j];
        //     }
        //     else if(j+1<n && i+1<n){
        //         dp[x] = grid[i][j]+min(dp[(i+1)*3 + j],dp[i*3 + j+1]);
        //     }else if(j+1==n){
        //         dp[x] = grid[i][j] + dp[(i+1)*3 + j];
        //     }else {
        //         dp[x] = grid[i][j] + dp[i*3 + j+1];
        //     }
            
        // }
        // return dp[0];



        // int n = grid.size();
        // vector<int> dp(n*n, 0);
        // //int x = i*3+j;
        // int i,j;
        // for(int x=(n*n)-1 ; x>=0;x--){
        //     j = x%3;
        //     i = x/3;
        //     cout<<i<<" "<<j<<endl;
        //     if(j+1 == n && i+1 == n){
        //         dp[x] = grid[i][j];
        //     }
        //     else if(j+1<n && i+1<n){
        //         dp[x] = grid[i][j]+min(dp[(i+1)*3 + j],dp[i*3 + j+1]);
        //     }else if(j+1==n){
        //         dp[x] = grid[i][j] + dp[(i+1)*3 + j];
        //     }else {
        //         dp[x] = grid[i][j] + dp[i*3 + j+1];
        //     }
            
        // }
        // return dp[0];
    }
};