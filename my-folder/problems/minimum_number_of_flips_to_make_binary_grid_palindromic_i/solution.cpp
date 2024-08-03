class Solution {
public:
    int palindromeRow(vector<int> row){
        int n=row.size();
        int ans=0;
        for(int i=0;i<n/2;i++){
            if(row[i]!=row[n-i-1]){
                ans++;
            }
        }
        return ans;
    }
    
    int minFlips(vector<vector<int>>& grid) {
        int ans=0,curr=0;
        for(int i=0;i<grid.size();i++){
            curr += palindromeRow(grid[i]);
        }
        ans=curr;
        curr=0;
        //for col
        vector<int> col;
        for(int j=0;j<grid[0].size();j++){
            for(int i=0;i<grid.size();i++){
                col.push_back(grid[i][j]);
            }
            curr += palindromeRow(col);
            col.clear();
        }

        
        return min(ans,curr);
    }
};