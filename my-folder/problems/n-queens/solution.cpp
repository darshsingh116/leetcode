#include<string>
class Solution {
public:
    string genPos(int pos, int size){
        string s="";
        for(int i=0;i<size;i++){
            if(i==pos){
                s=s+"Q";
            }else{
                s=s+".";
            }
        }
        return s;
    }
    bool check(int a,int b, int x,int y){
        if(abs(a-x) == abs(b-y) || a==x || b==y){
            return false;
        }
        return true;
    }

    void rec(vector<int> queens,int row,int n,vector<vector<string>>& ans){
        if(row>=n){
            vector<string> sq;
            for(auto pos:queens){
                sq.push_back(genPos(pos,n));
            }
            ans.push_back(sq);
            return;
        }
        int b;
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
                rec(queens,row+1,n,ans);
                queens.erase(queens.begin()+row);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> queens;
        rec(queens,0,n,ans);
        return ans;
    }

};