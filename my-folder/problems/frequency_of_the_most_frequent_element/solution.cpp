class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=1,ans=1,temp=k;
        long x ,curr=1;
        sort(nums.begin(),nums.end());
        while(j<n){
            x=(nums[j]-nums[j-1])*curr;
            if(x<=temp){
                temp -= x;
                curr++;
                j++;
                if(ans<curr){ans=curr;}
            }else{
                temp += nums[j-1]-nums[i];
                i++;
                curr--;
            }
            

        }

        return ans;
    }
};