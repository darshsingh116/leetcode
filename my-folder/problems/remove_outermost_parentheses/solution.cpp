class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=0;
        string ans;
        int cntr=0;
        
        while(i<s.size()-1){
            if(s[i]=='('){
                if(cntr>0){
                    ans=ans+'(';
                }
                cntr++;
            }else{
                if(cntr==1){
                    cntr--;
                }else if(cntr>1){
                    ans=ans+')';
                    cntr--;
                }
            }

            i++;
            
        }
        return ans;
    }
};