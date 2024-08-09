class Solution {
public:
    int help(vector<int>& prices, int canBuy, int day,int trans,vector<vector<int>>& dp){
        //if(day==prices.size()){return 0;}
        if(dp[day][canBuy]!=-1){return dp[day][canBuy];}
        int profit=0;
        if(canBuy){
            //not buy on this day , bought on this day
            profit = max(help(prices,1, day+1,trans,dp),(help(prices,0,day+1,trans+1,dp)-prices[day]));
            
            
        }else{
            profit = prices[day]+help(prices,1,day+1,trans,dp); //sell on this day
            profit = max(profit , help(prices,0,day+1,trans,dp)); //not sell today
            
        }
        dp[day][canBuy]=profit;
        
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        dp[prices.size()][0]=0;dp[prices.size()][1]=0;
        return help(prices,1,0,0,dp);
    }
};