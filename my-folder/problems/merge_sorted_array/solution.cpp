class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0,j=0;
        while(j<n || i<m){
            if(j==n){
                ans.push_back(nums1[i]);
                i++;
            }else if(i==m){
                ans.push_back(nums2[j]);
                j++;
            }
            else if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
       
       if(n!=0 && m!=0){nums1=ans;}
       else if(m==0){nums1=nums2;}
    }
};