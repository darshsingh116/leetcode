class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo(numCourses,0);
        vector<vector<int>> graph(numCourses,vector<int>());
        for(auto x: prerequisites){
            graph[x[1]].push_back(x[0]);
            topo[x[0]]++;
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(topo[i]==0){
                q.push(i);
            }
        }
        int curr;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            for(auto x:graph[curr]){
                topo[x]--;
                if(topo[x]==0){
                    q.push(x);
                }
            }
        }

        for(auto x:topo){
            if(x!=0){
                return false;
            }
        }

        return true;
    }
};