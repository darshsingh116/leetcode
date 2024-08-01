class Solution {
public:
    bool check(int i,int j,int sr, int sc){
        if(0<=sr && sr<i && 0<=sc && sc<j){
            return true;
        }
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int i=image.size(),j=image[0].size();
        int startColor = image[sr][sc];
        queue<pair<int,int>>q;
        set<pair<int,int>> visited;

        q.push({sr,sc});
        visited.insert({sr,sc});
        pair<int,int> curr;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            sr = curr.first;
            sc = curr.second;
            image[sr][sc] = color;
            if(check(i,j,sr-1,sc) && visited.find({sr-1,sc})==visited.end() && image[sr-1][sc]==startColor){
                q.push({sr-1,sc});
                visited.insert({sr-1,sc});
            }
            if(check(i,j,sr,sc-1) && visited.find({sr,sc-1})==visited.end() && image[sr][sc-1]==startColor){
                q.push({sr,sc-1});
                visited.insert({sr,sc-1});
            }
            if(check(i,j,sr,sc+1) && visited.find({sr,sc+1})==visited.end() && image[sr][sc+1]==startColor){
                q.push({sr,sc+1});
                visited.insert({sr,sc+1});
            }
            if(check(i,j,sr+1,sc) && visited.find({sr+1,sc})==visited.end() && image[sr+1][sc]==startColor){
                q.push({sr+1,sc});
                visited.insert({sr+1,sc});
            }
        }
        return image;
    }
};