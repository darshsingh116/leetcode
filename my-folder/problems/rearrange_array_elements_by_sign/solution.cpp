#include <iostream>
#include <queue>
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }else{
                 neg.push_back(nums[i]);
            }            
        }
        int x=0,y=0;
        for(int i=0;i<len;i++){
           
                nums[i]=pos[x];
                x++;
                i++;
                nums[i]=neg[y];
                y++;
                
            
        }
        return nums;
    }
};