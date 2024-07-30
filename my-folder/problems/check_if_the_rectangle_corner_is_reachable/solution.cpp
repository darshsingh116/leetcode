class Solution {
public:
    void makeEdge(vector<vector<int>>& edges, int i,int j,vector<vector<int>>& circles){
        long long a,b,r;
        a=circles[i][0]-circles[j][0];
        b=circles[i][1]-circles[j][1];
        r=circles[i][2]+circles[j][2];

        long long distanceSq = (a*a)+(b*b);
        if(distanceSq<=(r*r)){
            edges[i][j]=1;
            edges[j][i]=1;
        }
    }
    bool findPathTopBottom(vector<vector<int>>& edges,int currNode ,vector<vector<int>>& circles,vector<int>& circleTouchTopEdge,vector<int>& circleTouchBottomEdge,vector<int>& circleTouchRightEdge,int n,unordered_set<int>& visited){
        visited.insert(currNode);
        // cout<<"cum1 here"<<currNode<<endl;
        if(circleTouchBottomEdge[currNode]==1 || circleTouchRightEdge[currNode]==1){
            // cout<<"came1 here"<<endl;
            
            return false;
            }
        for(int i=0;i<n;i++){
            if(edges[currNode][i]==1  && currNode != i && visited.find(i)==visited.end()){
                // cout<<"came1 here for "<<currNode<<" "<<i<<endl;
                circleTouchBottomEdge[i] = !findPathTopBottom(edges,i,circles,circleTouchTopEdge,circleTouchBottomEdge,circleTouchRightEdge,n,visited);
                // visited.erase(visited.find(i));
                if(circleTouchBottomEdge[i]){
                    return false;
                }
            }
        }
        return true;

    }

    bool findPathLeftRight(vector<vector<int>>& edges,int currNode ,vector<vector<int>>& circles,vector<int>& circleTouchLeftEdge,vector<int>& circleTouchRightEdge,vector<int>& circleTouchBottomEdge,int n,unordered_set<int>& visited){

        // cout<<"cum2 here"<<currNode<<endl;
        visited.insert(currNode);
        if(circleTouchRightEdge[currNode]==1 || circleTouchBottomEdge[currNode]==1){
            // cout<<"came2 here"<<endl;
            return false;
            }
        for(int i=0;i<n;i++){
            if(edges[currNode][i]==1 && currNode != i && visited.find(i)==visited.end()){
                // cout<<"came2 here for "<<currNode<<" "<<i<<endl;
                circleTouchRightEdge[i]= !findPathLeftRight(edges,i,circles,circleTouchLeftEdge,circleTouchRightEdge,circleTouchBottomEdge,n,visited);
                // visited.erase(visited.find(i));
                if(circleTouchRightEdge[i]){
                    return false;
                }
            }
        }
        return true;

    }

    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n=circles.size();
        vector<vector<int>> edges(n,vector<int>(n,0));

        vector<int> circleTouchTopEdge(n,0);
        vector<int> circleTouchBottomEdge(n,0);
        vector<int> circleTouchLeftEdge(n,0);
        vector<int> circleTouchRightEdge(n,0);

        for(int i=0;i<n;i++){
            
            if(circles[i][1]+circles[i][2] >= Y){
                circleTouchTopEdge[i]=1;
            }
            if(circles[i][1]-circles[i][2] <= 0){
                circleTouchBottomEdge[i]=1;
            }
            if(circles[i][0]-circles[i][2] <= 0){
                circleTouchLeftEdge[i]=1;
            }
            if(circles[i][0]+circles[i][2] >= X){
                circleTouchRightEdge[i]=1;
            }

            if((circleTouchTopEdge[i]==1 && circleTouchBottomEdge[i]==1) || (circleTouchLeftEdge[i]==1 && circleTouchRightEdge[i]==1) || (circleTouchTopEdge[i]==1 &&circleTouchRightEdge[i]==1) || (circleTouchBottomEdge[i]==1 && circleTouchLeftEdge[i]==1)){
                return false;
            }

            for(int j=i;j<n;j++){
                makeEdge(edges,i,j,circles);
            }
            
        }

        

        // now we ave edges and know which circles touch edges
        // find a path from top to bottom  starting from any circle toughing top edge and ending to any circle touching bottom edge
        // if not found do same for left to right 
        // if not found return true else found in any case then false
        bool ans=false;
        unordered_set<int> visited;
        for(int i=0;i<n;i++){
            // cout<<i<<"circleTouchTopEdge now"<<endl;
            
            if(circleTouchTopEdge[i]==1){
                //find path and update ans if true
                if(!findPathTopBottom(edges,i,circles,circleTouchTopEdge,circleTouchBottomEdge,circleTouchRightEdge,n,visited)){
                    return false;
                }
            }
            visited.clear();
            
        }
        for(int i=0;i<n;i++){
            // cout<<i<<"circleTouchLeftEdge now"<<endl;
            if(circleTouchLeftEdge[i]==1){
                //find path and update ans if true

                if(!findPathLeftRight(edges,i,circles,circleTouchLeftEdge,circleTouchRightEdge,circleTouchBottomEdge,n,visited)){
                    return false;
                }
            }
            visited.clear();
        }

        
        return true;
        
        
    }
};