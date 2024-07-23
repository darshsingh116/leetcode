class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int b5=0,b10=0;

        for(int i=0;i<b.size();i++){
            if(b[i]==5){
                b5++;
            }else if(b[i]==10){
                if(b5==0){return false;}
                b10++;
                b5--;
            }else{
                if(b10==0){
                    if(b5<3){return false;}
                    b5=b5-3;

                }else if(b5 == 0){return false;}
                else{
                    b10--;
                    b5--;
                }
                
            }

        }
        return true;

        
    }
};