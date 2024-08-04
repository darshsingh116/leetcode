class Solution {
    public int[] plusOne(int[] digits) {
        int carry=0;
        int len = digits.length;
        int i=len-1;
        do{
            if(digits[i]==9){
                digits[i] = 0;
                carry=1;
            }else{
                digits[i]++;
                carry=0;
            }
            i--;
        }while(carry==1 && i>=0);

        if(i==-1 && carry==1){
            int[] ans=new int[len+1];
            ans[0]=1;
            return ans;
        }else{return digits;}
    }
}