#include <map>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> maps;
        vector<vector<int>> ans;
        int n = nums.size();
        int x;
        vector<int> temp;
        for(int i=0;i<n;i++){
            try{
                maps[nums[i]] = maps[nums[i]] + 1;
            }catch(...){
                maps[nums[i]] = 1;
            }
        }

        for (auto i = maps.begin(); i != maps.end(); i++){
            for (auto j = i; j != maps.end(); j++){
                if(i==j && j->second>1){
                    if((maps.count(0-(i->first)*2) != 0 && i->first != 0 )|| i->first == 0 && i->second >2){
                        temp.push_back(i->first);
                        temp.push_back(i->first);
                        temp.push_back(0-(i->first)*2);
                        ans.push_back(temp);
                        temp.clear();
                    }
                    
                }else if(i!=j){
                    x = 0-(i->first+j->first);                
                    if(maps.count(x) != 0 && i->first != x && j->first != x && x>i->first && x>j->first){
                        temp.push_back(i->first);
                        temp.push_back(j->first);
                        temp.push_back(x);
                        ans.push_back(temp);
                        temp.clear();
                    }
                }
            }            
        }

        return ans;
    }

};