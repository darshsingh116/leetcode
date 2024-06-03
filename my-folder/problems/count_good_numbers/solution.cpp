class Solution {
public:
long myPow(int x, long long n) {
        long ans = 1.0;
        long long nn = n;
        if(nn==0 || x==1){return 1;}
        if(nn<0){nn=0-nn;}
        if(x==0){return 0;}
        ans = myPow(x,nn/2)%1000000007;
        x=x%1000000007;
        if(nn%2==1){
            ans = x*ans*ans;
        }else{ ans = ans * ans; }

        if(n<0){
            return (1/ans);
        }else{
            return ans%1000000007;}

    }
    int countGoodNumbers(long long n) {
        long long prime,even;
        if(n==1){return 5;}
        if(n%2==1){
            prime = n/2+1;
        }else{prime = n/2;}
        even = n/2;
        long ans = ((myPow(4,even)%1000000007 * myPow(5,prime)%1000000007));
        
        return ans%1000000007;
    }
};