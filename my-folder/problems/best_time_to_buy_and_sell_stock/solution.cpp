class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int start = prices[0];
        int len = prices.size();
        int temp;
        for(int i=0;i<len;i++){
            temp = (prices[i]-start);
            if(max<temp){
                max = temp;
            }
            if(temp<0){
                start = prices[i];
            }
            if(start>=prices[i]){
                start = prices[i];
            }
        }

        return max;
    }
};