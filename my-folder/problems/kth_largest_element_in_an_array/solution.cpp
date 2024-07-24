class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        int i=k;
        while(k>1){
            pop_heap(nums.begin(),nums.end()-(i-k));
            k--;
        }
        return nums[0];
    }
};