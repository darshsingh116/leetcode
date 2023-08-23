class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int len = prices.size();
        int min;
        int diff = 0;
        min = prices[0];
        for(int i =1;i<len;i++){
            if(prices[i] < min){
                min = prices[i];
            }else if( (prices[i] - min) > diff){
                diff = prices[i] - min;
            }
        }
        
        return diff;
        
    }
};