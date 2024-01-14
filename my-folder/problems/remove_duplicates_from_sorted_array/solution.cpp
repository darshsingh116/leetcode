#include <set>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> myset;
        for(auto x:nums){
            myset.insert(x);
        }
        set<int,int>::iterator itr;
        int i=0;
        for (itr = myset.begin(); itr != myset.end(); itr++) {
        nums[i]=*itr;
        i++;
    }
       
        return myset.size();
    }
};