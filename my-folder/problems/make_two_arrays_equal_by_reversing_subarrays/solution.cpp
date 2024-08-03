class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mymap;

        for(auto x:target){
            if(mymap.find(x)==mymap.end()){
                mymap[x]=1;
            }else{
                mymap[x]++;
            }
        }

        for(auto x:arr){
            if(mymap.find(x)==mymap.end()){
                return false;
            }else{
                if(mymap[x]>0){
                    mymap[x]--;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};