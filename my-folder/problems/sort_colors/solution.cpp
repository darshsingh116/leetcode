class Solution {
public:
    void sortColors(vector<int>& nums) {
       int hash[2] = {0,0};
       vector<int> ans;
       cout<<"[";
       int len =nums.size();
       for(int i=0;i<len;i++){
        if(nums[i]==0){ans.push_back(0);cout<<0;}
        else{hash[nums[i]-1]++;}  
       }

       for(int i=0;i<hash[0];i++){
        ans.push_back(1);cout<<1;
       }
       for(int i=0;i<hash[1];i++){
        ans.push_back(2);cout<<2;
       }

       nums=ans;
    }
};