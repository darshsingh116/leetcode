class Solution {
public:

    int split( vector<int>& arr,int a, int b ,int min){
        if(a == b){
            if(min>arr[a]){min = arr[a];}
        }
        else{
            int c = (a+b)/2;
            int x = split( arr,  a, c , min);
            int y = split( arr,  c+1, b , min);

            if(x>y){min = y;}else{min = x;}
        }

        return min;
    }

    int findMin(vector<int>& nums) {
    return split(nums , 0,nums.size()-1,nums[0]);    
    }
};