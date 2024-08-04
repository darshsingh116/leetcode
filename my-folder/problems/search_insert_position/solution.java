class Solution {
    public int searchInsert(int[] nums, int target) {
        int start=0,end=nums.length-1,mid;

        while(start<end){
            mid=(start+end)/2;

            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid]){
                end=mid;
            }else{
                start=mid+1;
            }
        }
        if(nums[start]>=target){return start;}
        return start+1;
    }
}