class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        int n=s.size();
        s=s+" ";
        string temp;
        for(int i=0;i<=n;i++){
            if(s[i]==' '){
                if(temp.size()>0){
                    stk.push(temp);
                    cout<<temp<<endl;
                }
                temp="";
            }else{
                temp=temp+s[i];
            }
        }
        temp="";
        while(true){
            temp=temp+stk.top();
            stk.pop();
            if(stk.empty()){
                break;
            }else{
                temp=temp+" ";
            }

        }
        return temp;
    }
};