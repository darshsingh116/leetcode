class Solution {
public:
    bool isEdge(pair<int,int> curr,int i, int j){
        if(curr.first==i-1 || curr.first==0 || curr.second ==0 ||curr.second==j-1 ){
            return true;
        }
        return false;
    }
    vector<vector<char>> bfs(vector<vector<char>> oldboard,map<pair<int,int>,bool>& visited,pair<int,int> start){
        vector<vector<char>> board = oldboard;
        int i = board.size();
        int j=board[0].size();
        queue<pair<int,int>> q;
        q.push(start);
        visited[start]=1;
        pair<int,int> curr;
        bool hasEdge =false;

        while(!q.empty()){
            curr = q.front();
            board[curr.first][curr.second] = 'X';
            q.pop();
            if(isEdge(curr,i,j)){
                hasEdge = true;
            }

            if((curr.first+1<i) && board[curr.first+1][curr.second]=='O' && visited[{curr.first+1,curr.second}]==0){
                q.push({curr.first+1,curr.second});
                visited[{curr.first+1,curr.second}]=1;
            }
            if((curr.first-1>=0) && board[curr.first-1][curr.second]=='O' && visited[{curr.first-1,curr.second}]==0){
                q.push({curr.first-1,curr.second});
                visited[{curr.first-1,curr.second}]=1;
            }
            if((curr.second+1<j) && board[curr.first][curr.second+1]=='O' && visited[{curr.first,curr.second+1}]==0){
                q.push({curr.first,curr.second+1});
                visited[{curr.first,curr.second+1}]=1;
            }
            if((curr.second-1>=0) && board[curr.first][curr.second-1]=='O' && visited[{curr.first,curr.second-1}]==0){
                q.push({curr.first,curr.second-1});
                visited[{curr.first,curr.second-1}]=1;
            }

        }
        if(hasEdge){
            return oldboard;
        }
        // cout<<start.first<<" "<<start.second<<endl;
        return board;



    }
    void solve(vector<vector<char>>& board) {
        map<pair<int,int>,bool> visited;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    visited[{i,j}]=0;
                }
            }
        }

        for(auto x:visited){
            if(x.second == 0){
                board = bfs(board,visited,x.first);
                //bfs for x.first pair
            }
        }


    }
};