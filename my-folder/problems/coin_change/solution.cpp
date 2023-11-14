class Solution {
public:


    int coinChange(vector<int>& coins, int amount) {
        int table[(amount+1)];    
        for(int i=1;i <= amount ;i++){
            int min= -1;
            table[i] = -1;
            for(int j=coins.size()-1;j>=0;j--){ 
                
                if(coins[j]==i){min = 1;break;}
                if(coins[j]<i){
                    int diff = i-coins[j];
                    
                    if(diff<i && table[diff]!= -1){
                    int x = 1 + table[diff];
                   
                    if(x<min || min == -1){min = x;}
                    }
                }
                
               
            }
            table[i] = min;
            
        }
        return (amount != 0)?table[amount]:0;
    }
};