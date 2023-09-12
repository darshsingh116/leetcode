class Solution {
public:

    //int num=0;
    int arr[46] = {0};
    int func(int n){  
        int ret=0;  
        
        if(n == 1){return 1;}
        if(n == 2){return 2;}

        if(n>0){
            
            if(arr[n-1] == 0) {arr[n-1] = func(n-1);}
            ret = ret + arr[n-1];
            
            if(arr[n-2] == 0) {arr[n-2] = func(n-2);}
            ret = ret + arr[n-2];
        }
       
        
        return ret;
    }
    int climbStairs(int n) {
        
        return func(n);
    }
};