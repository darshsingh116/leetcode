class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int i,int j){
        // cout<<"grid i size"<<grid.size()<<endl;
        // cout<<"grid j size"<<grid[0].size()<<endl;
        cout<< i<< " "<<j<<" : ";
        if(0<=i && i<grid.size() && 0<=j && j<grid[0].size()){
            cout<<" is inbound : ";
            if(grid[i][j]==1){
                cout<<"true"<<endl;
                return true;
            }else{cout<<endl;}
        }else{cout<<endl;}
        return false;
    }
    void addToBfs(vector<vector<int>>& grid,int i,int j,set<pair<int,int>>& visited,queue<pair<int,int>>& q , int& nextLvlCount,int& level ,int& repeat){
        
        if(0<=i && i<grid.size() && 0<=j && j<grid[0].size()){
            pair<int,int> temp;
            temp.first=i;
            temp.second=j;
            if((grid[i][j]==1) && visited.find(temp)==visited.end()){
                visited.insert(temp);
                q.push(temp);
                nextLvlCount++;
                // if(grid[i][j]==2){
                //     repeat = level/2;
                //     level -= repeat;
                //     if(repeat>0){
                //         repeat--;
                //     }
                // }
            }

        }
    }

    int bfs(vector<vector<int>>& grid,set<pair<int,int>>& visited, vector<pair<int,int>>& startings){
        int level = -1;
        queue<pair<int,int>> q;
        pair<int,int> temp;
        int lvlCount=0;
        for(int i=0;i<startings.size();i++){
            q.push(startings[i]);
            lvlCount++;
            visited.insert(startings[i]);
        }
        int nextLvlCount=0;
        int a,b;
        temp=q.front();
        int repeat=0;
        while(!q.empty()){
            temp=q.front();
            a=temp.first;
            b=temp.second;
            q.pop();
            lvlCount--;
            cout<<a<<" "<<b<<endl;
            cout<<"level "<<level<<endl;

            addToBfs(grid,a-1,b,visited,q ,nextLvlCount,level,repeat);
            addToBfs(grid,a,b-1,visited,q ,nextLvlCount,level,repeat);
            addToBfs(grid,a,b+1,visited,q ,nextLvlCount,level,repeat);
            addToBfs(grid,a+1,b,visited,q ,nextLvlCount,level,repeat);

            if(lvlCount==0){
                // cout<<nextLvlCount<<endl;
                lvlCount=nextLvlCount;
                nextLvlCount = 0;
                level++;

            }
            
        }
        
        return level;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        set<pair<int,int>> visited;
        pair<int,int> start;
        int ans =-1;
        vector<pair<int,int>> startings;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                start.first = i;
                start.second=j;
                if(grid[i][j]==2){
                    startings.push_back(start);
                }
            }
        }
        
        //bfs
        ans = bfs(grid,visited,startings);

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    start.first = i;
                    start.second=j;
                    if(visited.find(start) == visited.end()){
                        cout<<"this not found"<<start.first<<" "<<start.second<<endl;
                        return -1;
                    }
                }
            }   
        }
        if(startings.size()==0){
            return 0;
        }

        
        return ans;
    }
};