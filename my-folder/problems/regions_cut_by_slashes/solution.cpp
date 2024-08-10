class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>> a(3,vector<int>(3,0));
        a[0][0]=1;a[1][1]=1;a[2][2]=1;
        vector<vector<int>> b(3,vector<int>(3,0));
        b[0][2]=1;b[1][1]=1;b[2][0]=1;
        vector<vector<int>> c(3,vector<int>(3,0));

        vector<vector<int>> temp;
        vector<vector<int>> mygrid(n*3,vector<int>(n*3));


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='\\'){temp=a;}
                else if(grid[i][j]=='/'){temp=b;}
                else{temp=c;}
                mygrid[i*3+0][j*3+0]=temp[0][0];
                mygrid[i*3+0][j*3+1]=temp[0][1];
                mygrid[i*3+0][j*3+2]=temp[0][2];
                mygrid[i*3+1][j*3+0]=temp[1][0];
                mygrid[i*3+1][j*3+1]=temp[1][1];
                mygrid[i*3+1][j*3+2]=temp[1][2];
                mygrid[i*3+2][j*3+0]=temp[2][0];
                mygrid[i*3+2][j*3+1]=temp[2][1];
                mygrid[i*3+2][j*3+2]=temp[2][2];
            }
        }

        int ans=0;
        queue<pair<int,int>> q;
        pair<int,int> curr;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                if(mygrid[i][j]==0){
                    ans++;
                    mygrid[i][j]=2;
                    q.push({i,j});
                }

                while(!q.empty()){
                    curr=q.front();
                    q.pop();
                    
                    if(0<=(curr.first-1) && (curr.first-1)<n*3 && 0<=curr.second && curr.second<n*3){
                        if(mygrid[curr.first-1][curr.second]==0){
                            mygrid[curr.first-1][curr.second]=2;
                            q.push({curr.first-1,curr.second});
                        }
                    }
                    if(0<=(curr.first+1) && (curr.first+1)<n*3 && 0<=curr.second && curr.second<n*3){
                        if(mygrid[curr.first+1][curr.second]==0){
                            mygrid[curr.first+1][curr.second]=2;
                            q.push({curr.first+1,curr.second});
                        }
                    }
                    if(0<=(curr.first) && (curr.first)<n*3 && 0<=(curr.second-1) && (curr.second-1)<n*3){
                        if(mygrid[curr.first][curr.second-1]==0){
                            mygrid[curr.first][curr.second-1]=2;
                            q.push({curr.first,curr.second-1});
                        }
                    }
                    if(0<=(curr.first) && (curr.first)<n*3 && 0<=(curr.second+1) && (curr.second+1)<n*3){
                        if(mygrid[curr.first][curr.second+1]==0){
                            mygrid[curr.first][curr.second+1]=2;
                            q.push({curr.first,curr.second+1});
                        }
                    }
                }
                // cout<<mygrid[i][j];
            }
            // cout<<endl;
        }


        return ans;
    }
};

