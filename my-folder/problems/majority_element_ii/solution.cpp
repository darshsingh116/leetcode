#include <unordered_map>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        int n=size/3;
        unordered_map<int,int> map;

        for(int i=0;i<size;i++){
            try{
                map[nums[i]]=map[nums[i]]+1;
            }catch(...){
                map[nums[i]]=1;
            }
            
            if(map[nums[i]]>n && map[nums[i]] <= size){
                ans.push_back(nums[i]);
                map[nums[i]] = map[nums[i]] + size;
            }
        }

        return ans;

    }
};