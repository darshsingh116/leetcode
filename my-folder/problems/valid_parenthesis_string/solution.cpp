class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stk;
        set<int> myset1,myset2;
        int temp;

        // pair<char,int> temp;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(i);
            }else if(s[i]==')'){
                if(!stk.empty()){
                    stk.pop();
                }else{
                    myset2.insert(i);
                }
            }else{
                myset1.insert(i);
            }
        }

        set<int>::iterator itr1= myset1.begin(),itr2= myset2.begin();
        set<int>::reverse_iterator rit1;
        if(!stk.empty()){
            //extra (
            rit1 = myset1.rbegin();
            while(!stk.empty()){
                temp = stk.top();
                stk.pop();
                if(rit1 == myset1.rend()){
                    return false;
                }
                
                if(temp < *rit1){
                    rit1++;
                }else{
                    return false;
                }
            }

        }
        if(!myset2.empty()){
            //extra )
            itr1= myset1.begin(),itr2= myset2.begin();
            while(itr2 != myset2.end()){
                if(itr1 == myset1.end()){
                    return false;
                }
                if(*itr2 > *itr1){
                    itr1++;
                    itr2++;
                }else{
                    return false;
                }
            }
        }


        return true;
    }

};