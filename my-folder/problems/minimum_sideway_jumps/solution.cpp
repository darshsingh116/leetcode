class Solution {
public:
    int rec(vector<int>& obstacles,int pos,int lane,vector<int>& dp){
        // cout<<"pos "<<pos<<" lane "<<lane<<endl;
        if(pos==obstacles.size()-1){return 0;}
        while(obstacles[pos+1]!=lane){
            pos++;
            if(pos==obstacles.size()-1){return 0;}
        }
        if(dp[pos]!= -1){
            return dp[pos];
        }
        int ans;

        if(lane==2){
            if(obstacles[pos]==1){ans = 1+rec(obstacles,pos,3,dp);}
            else if(obstacles[pos]==3){//3
                ans= 1+rec(obstacles,pos,1,dp);
            }else{
                ans= 1+min(rec(obstacles,pos,1,dp),rec(obstacles,pos,3,dp));
            }
        }else if(lane==3){
            if(obstacles[pos]==2){ans= 1+rec(obstacles,pos,1,dp);}
            else if(obstacles[pos]==1){//1
                ans= 1+rec(obstacles,pos,2,dp);
            }else{
                ans= 1+min(rec(obstacles,pos,2,dp),rec(obstacles,pos,1,dp));
            }
        }else{
            if(obstacles[pos]==2){
                ans= 1+rec(obstacles,pos,3,dp);}
            else if(obstacles[pos]==3){//1
                ans= 1+rec(obstacles,pos,2,dp);
            }else{
                ans= 1+min(rec(obstacles,pos,2,dp),rec(obstacles,pos,3,dp));
            }
        }
        dp[pos]= ans;
        return ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<int> dp(obstacles.size()+1,-1);
        return rec(obstacles,0,2,dp);
    }
};