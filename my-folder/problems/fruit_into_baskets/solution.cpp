class Solution {
public:
    int totalFruit(vector<int>& f) {
        
        int n = f.size();
        int ans=0,currans=0;
        if(n<3){
            return n;
        }
        int i=0,j=0;
        int a=f[0],b=f[0];

        while(j<n){
            // cout<<i<<" "<<j<<endl;
            while(j<n&&(a==b || f[j]==a || f[j]==b)){
                if(a==b){
                    b=f[j];
                }
                cout<<j<<" ";
                currans++;
                j++;
            }
            
            //cout<<i<<" "<<j<<endl;
            ans=max(ans,currans);
            if(j==n){return ans;}
            currans=0;
            i=j-1;
            while(f[i]==f[j-1]){
                i--;
                currans++;
            }
            i++;
            a=f[i];
            b=f[j];

        }

        return ans;
    }
};