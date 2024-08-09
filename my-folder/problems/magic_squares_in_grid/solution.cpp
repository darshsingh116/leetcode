class Solution {
public:
    bool isMagic(vector<vector<int>>& grid,int i,int j){
        vector<int> table(9,0);
        for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                if(grid[i+a][j+b]>9 || grid[i+a][j+b]<1){return false;}
                if(table[grid[i+a][j+b]-1]==0){
                    table[grid[i+a][j+b]-1]=1;
                }else{
                    return false;
                }
                
            }
        }
        
        int sum = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        
        for(int k=0;k<3;k++){
            if(sum!=grid[i+k][j]+grid[i+k][j+1]+grid[i+k][j+2]){
                return false;
            }
            if(sum!=grid[i][j+k]+grid[i+1][j+k]+grid[i+2][j+k]){
                return false;
            }
        }
        if(sum!=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]){
            return false;
        }

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 && grid[0].size()<3){return 0;}
        int ans=0;
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid[0].size()-2;j++){
                if(isMagic(grid,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

// [3,2,9,2,7]
// [6,1,8,4,2]
// [7,5,3,2,7]
// [2,9,4,9,6]
// [4,3,8,2,5]