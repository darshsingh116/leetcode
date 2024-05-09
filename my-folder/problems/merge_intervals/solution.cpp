class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        vector<vector<int>> ans;
        if(len==0){
            return ans;
        }
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int k=0;
        for(int i=1;i<len;i++){
            if(intervals[i][0]<=ans[k][1] && intervals[i][1]>=ans[k][0]){
                ans[k][0]=min(intervals[i][0],ans[k][0]);
                ans[k][1]=max(intervals[i][1],ans[k][1]);
            }else{
                ans.push_back(intervals[i]);
                k++;
            }
        }
        return ans;
    }
};