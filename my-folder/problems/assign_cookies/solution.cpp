class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gs = g.size(),ss=s.size();

        int i=0,j=0,ans=0;
        while(i<gs){
            if(j==ss){break;}
            if(g[i]<=s[j]){
                ans++;i++;j++;
            }else{
                j++;
            }
        }
        return ans;
    }
};