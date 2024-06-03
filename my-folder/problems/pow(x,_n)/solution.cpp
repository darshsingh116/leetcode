class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nn = n;
        if(nn==0 || x==1){return 1;}
        if(nn<0){nn=0-nn;}
        if(x==0){return 0;}
        ans = myPow(x,nn/2);
        if(nn%2==1){
            ans = x*ans*ans;
        }else{ ans = ans * ans; }

        if(n<0){
            return (1/ans);
        }else{return ans;}

    }
};