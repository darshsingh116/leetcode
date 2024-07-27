class Solution {
public:
    long long mymin(long long a,long long b){
        if(a<b){
            return a;
        }else{
            return b;
        }
        return a;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> matrix(26,vector<long long>(26,LLONG_MAX));
        
        for(int i=0;i<26;i++){
            matrix[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            if(matrix[original[i]-'a'][changed[i]-'a']!=LLONG_MAX){cout<<"wow"<<endl;}
            matrix[original[i]-'a'][changed[i]-'a'] = mymin(cost[i],matrix[original[i]-'a'][changed[i]-'a']);
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                // cout<<matrix[i][j]<<" ";
                for(int k=0;k<26;k++){
                    if(matrix[j][i]!=LLONG_MAX && matrix[i][k]!=LLONG_MAX){
                        matrix[j][k] = mymin(matrix[j][k],matrix[j][i]+matrix[i][k]);
                        }
                }
            }
            // cout<<endl;
        }
        // cout<<original[0]-'a';

        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(matrix[source[i]-'a'][target[i]-'a']!=LLONG_MAX){
                ans += matrix[source[i]-'a'][target[i]-'a'];
            }else{
                return -1;
            }
            
        }
        return ans;
    }
};