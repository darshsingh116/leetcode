class Solution {
public:
    bool inRange(int i,int j,int m,int n){
        if(0<=i && i<m && 0<=j && j<n){
            return true;
        }
        return false;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        int i,j,a,b;
        dp[m-1][n-1]=1;
        for(b=n-2;b>=0;b--){
            a=m-1;
            j=b;
            i=a;
            while(inRange(i,j,m,n)){
                if(inRange(i,j+1,m,n)){
                    dp[i][j] += dp[i][j+1];
                }
                if(inRange(i+1,j,m,n)){
                     dp[i][j] += dp[i+1][j];
                }
                i--;j++;
            }
        }

        for(a=m-2;a>=0;a--){
            j=0;
            i=a;
            while(inRange(i,j,m,n)){
                if(inRange(i,j+1,m,n)){
                    dp[i][j] += dp[i][j+1];
                }
                if(inRange(i+1,j,m,n)){
                     dp[i][j] += dp[i+1][j];
                }
                i--;j++;
            }
        }

        return dp[0][0];
        
    }
};