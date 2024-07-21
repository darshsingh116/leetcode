class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> myset;
        int n = s.size();
        if(n<2){
            return n;
        }
        int i=0,j=0,max=0,curr=0;
        while(j<n){
            if(myset.find(s[j]) == myset.end()){
                myset.insert(s[j]);
                curr++;
                j++;
            }else{
                while(s[i]!=s[j]){
                    myset.erase(s[i]);
                    i++;
                    curr--;
                }
                myset.erase(s[i]);
                curr--;
                i++;
            }

            if(curr>max){max=curr;}
        }

        return max;
    }
};