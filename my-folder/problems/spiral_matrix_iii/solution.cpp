class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        enum Directions {up, down, left, right};
        int n=rows*cols;
        int i=1;
        int sq=1,currsq=1;
        Directions dir = right;
        int x=rStart,y=cStart;

        vector<vector<int>> ans;

        while(i<=n){
            if(0<=x && x<rows && 0<=y && y<cols){
                ans.push_back({x,y});
                i++;
            }
            if(dir==right){
                if(currsq!=0){
                    y++;currsq--;
                }else{
                    dir=down;
                    currsq=sq;
                    x++;currsq--;
                }
            }else if(dir==down){
                if(currsq!=0){
                    x++;currsq--;
                }else{
                    dir=left;
                    currsq=sq;
                    y--;currsq--;
                }
            }else if(dir==left){
                if(currsq!=0){
                    y--;currsq--;
                }else{
                    dir=up;
                    y--;sq+=2;currsq=sq;currsq--;
                }
            }else{
                if(currsq!=0){
                    x--;currsq--;
                }else{
                    dir=right;
                    currsq=sq;
                    y++;currsq--;
                }
            }
        }
        return ans;
    }
};