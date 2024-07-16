class Solution {
public:
    
    long long subprob(string s, int i, int prev , vector<long long>& dp){
        if(i==s.length()){
            if(prev=='0'){
                return 1;
            }else{
                return 0;
            }
            
        }
        if(prev=='0'){
            //all valid except 0
            //we can take pairs also for next
            if(s[i]=='0'){return 0;}
            if(dp[i]!=-1){return dp[i];}
            long long len = (subprob(s,i+1,'0',dp) + subprob(s,i+1,s[i],dp));
            dp[i] = len;
            return len;
            
        }else if(prev=='1'){
            //all valid   
            return subprob(s,i+1,'0',dp);
        }else if(prev=='2'){
            //0 to 6 valid
            if(s[i]<='6'){
                return subprob(s,i+1,'0',dp);
            }
            
        }

        return 0;

    }

    long long numDecodings(string s) {
        // vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        vector<long long> dp(s.length()+1,-1);
        return subprob(s,0,'0',dp);
    }
};