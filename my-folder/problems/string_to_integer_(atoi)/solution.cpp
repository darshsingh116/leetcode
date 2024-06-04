class Solution {
public:
    int myAtoi(string s) {
        int len =  s.size();
        long ans = 0;
        int sign=false;
        bool neg = false;
        for(int i=0;i<len;i++){
            if((s[i]) == ' ' && !sign){continue;}
            if(s[i] == '-' || s[i] == '+'){
                
                if(!sign){
                    if(s[i]=='-'){neg=true;}
                    sign=true; continue;
                    }
                else{break;}
            }
            if(int(s[i])>47 && int(s[i])<58){
                sign = true;
                cout<<neg<<endl;
                ans = ans*10 + int(s[i]) - 48;
                if(neg && ans>INT_MAX){
                        return INT_MIN;
                    }
                else if(ans > INT_MAX){                    
                    return INT_MAX;
                }
            }else{break;}
        }
        if(neg){ans=0-ans;}
        return ans;

    }
};