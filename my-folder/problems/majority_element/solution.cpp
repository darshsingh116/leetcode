class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=0;
        int frequency=0;
        for(int i=0;i<nums.size();i++){
            if(frequency==0){
                element=nums[i];
            }
            if(element==nums[i]){
                frequency++;
            }
            else{
                frequency--;
            }
            
        }
        return element;
    }
};