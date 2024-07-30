class Solution {
public:
 bool inRange(int i,int j,int m,int n){
        if(0<=i && i<m && 0<=j && j<n){
            return true;
        }
        return false;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n= obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]==1){return 0;}

        vector<vector<long long>> dp(m,vector<long long>(n,INT_MAX));
        int i,j,a,b;
        dp[m-1][n-1]=1;
        for(b=n-2;b>=0;b--){
            a=m-1;
            j=b;
            i=a;
            while(inRange(i,j,m,n)){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else{
                    if(inRange(i,j+1,m,n) && inRange(i+1,j,m,n)){
                        dp[i][j] = dp[i][j+1]+dp[i+1][j];
                    }else if(inRange(i+1,j,m,n)){
                        dp[i][j] = dp[i+1][j];
                    }else{
                        dp[i][j] = dp[i][j+1];
                    }
                }
                
                i--;j++;
            }
        }

        for(a=m-2;a>=0;a--){
            j=0;
            i=a;
            while(inRange(i,j,m,n)){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else{
                    if(inRange(i,j+1,m,n) && inRange(i+1,j,m,n)){
                        dp[i][j] = dp[i][j+1]+dp[i+1][j];
                    }else if(inRange(i+1,j,m,n)){
                        dp[i][j] = dp[i+1][j];
                    }else{
                        dp[i][j] = dp[i][j+1];
                    }
                }
                
                i--;j++;
            }
        }

        return dp[0][0];

    }
};