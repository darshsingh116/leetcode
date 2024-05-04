#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
// -2,-1,0,0,1,2
        set<vector<int>> ans;
        vector<int> temp;
        map<long long,int> maps;
        sort(nums.begin(),nums.end());
        
        
        int n = nums.size();
       for(int i=0;i<n;i++){
            try{
                maps[nums[i]] = maps[nums[i]] + 1;
            }catch(...){
                maps[nums[i]] = 1;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long long ii = nums[i];
                    long long jj = nums[j];
                    long long kk = nums[k];
                    long long targett = target;
                    long long x = targett-(ii+jj+kk);
                    if(maps.count(x)!=0){
                        int count = 1;
                        if(ii==x){count++;}
                        if(jj==x){count++;}
                        if(kk==x){count++;}
                        if(maps[x]>=count){
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[k]);
                            temp.push_back(x);
                            sort(temp.begin(),temp.end());
                            ans.insert(temp);
                            temp.clear();
                        }
                    }
                }
            }
        }
        vector<vector<int>> anss(ans.begin(),ans.end());
        return anss;
    }
};