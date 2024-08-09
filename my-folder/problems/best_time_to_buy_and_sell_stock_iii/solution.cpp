class Solution {
public:
    int help(vector<int>& prices, bool canBuy, int day,int trans,vector<vector<vector<int>>>& dp){
        if(day==prices.size()){return 0;}
        if(dp[day][canBuy][trans]!=-1){return dp[day][canBuy][trans];}
        int profit=0;
        if(canBuy){
            if(trans<2){
                //not buy on this day , bought on this day
                profit = max(help(prices,true, day+1,trans,dp),(help(prices,false,day+1,trans+1,dp)-prices[day]));
            }
        }else{
            profit = prices[day] + help(prices,true,day+1,trans,dp); //sell on this day
            profit = max(profit , help(prices,false,day+1,trans,dp)); //not sell today
        }
        dp[day][canBuy][trans]=profit;
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return help(prices,true,0,0,dp);
    }
};