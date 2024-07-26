class Solution {
public:
    void warshal(vector<vector<int>>& myedges,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    //j,k = j,i+i,k;
                    if(myedges[j][i]!=INT_MAX && myedges[i][k]!=INT_MAX ){
                        myedges[j][k]=min(myedges[j][k], myedges[j][i]+myedges[i][k]);
                    }
                    
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> sol;
        vector<vector<int>> myedges(n, vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            myedges[edges[i][0]][edges[i][1]] = edges[i][2];
            myedges[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0;i<n;i++){
            myedges[i][i] = 0;
        }
        int ansmin=n,anscity=0,cities=0;

        warshal(myedges,n);

        for(int i=0;i<n;i++){
            cities=0;
            
            for(int j=0;j<n;j++){
                cout<<j<<" : "<<myedges[i][j]<<endl;
                if(myedges[i][j]<=distanceThreshold){
                    cities++;
                }
            }
            
            cout<<"city : "<<i<<" neighboring :  "<<cities<<endl;
            if(ansmin>=cities){
                ansmin=cities;
                anscity = i;
            }

        }
        

        return anscity;
    }
};