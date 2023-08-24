class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int mid;
        int high = nums.size() - 1;

        int tlow,tmid,thigh;

        while(low <= high){

            mid = (high+low)/2;

            tlow = low;
            tmid = mid;
            thigh = high;

            if(high == low){ 
                if(nums[low]==target){return low;}
                else{break;}
                    
                }
            cout << low << " " << mid << " "<< high << " " <<endl;
            if(nums[mid] >= nums[low]){
                if(nums[low] <= target && nums[mid] >= target){
                    thigh = mid;
                }else{ tlow = mid + 1; } 
            }
            if(nums[mid+1] <= nums[high]){
                if(nums[mid+1] <= target && nums[high] >= target){
                    tlow = mid + 1;
                }else{thigh = mid;}  
            }

            high= thigh;
            low = tlow;
            mid = tmid;
            //cout << low << " " << mid << " "<< high << " " <<endl;
           
        }

        return -1;
    }
};