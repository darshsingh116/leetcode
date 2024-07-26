class Solution {
public:
    int dfs(vector<vector<int>>& isConnected , int start, unordered_set<int>& visited){
        visited.insert(start);
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[start][i]){
                if(visited.find(i)==visited.end()){
                    dfs(isConnected,i,visited);
                }
                
            }
        }
        return 1;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        unordered_set<int> visited;
        for(int i=0;i<isConnected.size();i++){
            if(visited.find(i)==visited.end()){
                ans += dfs(isConnected,i,visited);
            }
        }
        return ans;
    }
};
// ````1 2 3
//   1 1 1 0
//   2 1 1 0
//   3 0 0 1