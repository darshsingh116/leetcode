class Solution {
public:

    int minimumDeletions(string s) {
        
        if(s.size()<=1){return 0;}
        s+='b';
        s='a'+s;
        int n=s.size();
        vector<int> dpFwd(n,0);
        vector<int> dpBkwd(n,0);
        
        
        for(int i=1;i<n;i++){
            if(s[i-1]=='b'){
                dpFwd[i] = dpFwd[i-1] + 1;
            }else{
                dpFwd[i] = dpFwd[i-1];
            }
            if(s[n-i]=='a'){
                dpBkwd[n-i-1] = dpBkwd[n-i] +1;
            }else{
                dpBkwd[n-i-1] = dpBkwd[n-i];
            }
        }

        // handle if all a or all b
        if(dpFwd[n-1]==0 || dpBkwd[0]==0){
            return 0;
        }

        //else
        int i=0;
        int j=n-1;
        
        while(s[i]!='b'){
            i++;
        }
        while(s[j-1]!='a'){
            j--;
        }

        int ans=INT_MAX;
        while(i<=j){
            if(s[i]=='b'){
                ans = min(ans,(dpFwd[i]+dpBkwd[i]));
                cout<<dpFwd[i]+dpBkwd[i]<<endl;
            }
            i++;
        }


        return ans;
        
    }
};