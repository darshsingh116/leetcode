#include<string>
class Solution {
public:
    
    bool check(int a,int b, int x,int y){
        if(abs(a-x) == abs(b-y) || a==x || b==y){
            return false;
        }
        return true;
    }

    int rec(vector<int> queens,int row,int n){
        if(row>=n){
            return 1;
        }
        int b;
        int ans=0;
        for(int i=0;i<n;i++){
            bool isvalid=true;
            for(int a=0;a<queens.size();a++){
                b=queens[a];
                if(!check(a,b,row,i)){
                    isvalid=false;
                    break;
                }
            }
            if(isvalid){
                queens.push_back(i);
                ans += rec(queens,row+1,n);
                queens.erase(queens.begin()+row);
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<int> queens;     
        return rec(queens,0,n);
    }

};