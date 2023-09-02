class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> myarr(n, vector<int>(n));

        int i=0,j=0;
        bool fwd=true,rev=false,up=false,dwn=true;
        int top=1,btm=(n-1),lt=0,rt=(n-1);
        cout<<"hi";
        for(int k=1 ;k<=(n*n);k++){
            //cout << k <<endl;
            if(fwd){
                //cout<<"fwd" <<i<<j<<endl;
                myarr[i][j] = k;
                if(j==rt){fwd=false;dwn=true;rt--;i++;}
                else{j++;}
            }
            else if(dwn){
                
                //cout <<"dwn"<<i<<j<<endl;
                myarr[i][j] = k;
                if(i==btm){dwn=false;rev=true;btm--;j--;}
                else{i++;}
            }
            else if(rev){
                
                //cout <<"rev"<<i<<j<<endl;
                myarr[i][j] = k;
                if(j==lt){rev=false;up=true;lt++;i--;}
                else{j--;}
            }
            else if(up){
                //cout <<"up"<<i<<j<<endl;
                myarr[i][j] = k;
                if(i==top){up=false;fwd=true;top++;j++;}
                else{i--;}
            }
        }
//00 01 02 12 22 21 20 10 11

        return myarr;
    }
};