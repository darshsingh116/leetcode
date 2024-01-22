class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(k>len){
            k=k%len;
        }
        if(k!=0){
            int arr[k];
            for(int i=k;i>0;i--){
                arr[k-i]= nums[len-i];
            }
            for(int i=len-k-1 ; i>=0;i--){
                nums[i+k]=nums[i];
            }
            for(int i=0;i<k;i++){
                nums[i]=arr[i];
            }
        }
    }
};