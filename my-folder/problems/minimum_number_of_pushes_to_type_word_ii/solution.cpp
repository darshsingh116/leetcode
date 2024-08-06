class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(auto c:word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end());
        int keyleft=8,level=1,ans=0;
        for(int i=25;i>=0;i--){
            if(freq[i]==0){
                break;
            }
            keyleft--;
            ans+=freq[i]*level;
            if(keyleft==0){
                level++;
                keyleft=8;
            }
        }
        return ans;
    }
};