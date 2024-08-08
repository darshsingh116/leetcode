class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans=0;
        cout<<tasks.size();
        unordered_map<char,int>m;
        for(auto x:tasks){m[x]++;}

        priority_queue<pair<int,int>> pq; //<freq left,last pos> //maxeap
        for(auto x:m){
            // cout<<x.second<<" "; /////
            pq.push({x.second,-1});
        }
        // cout<<endl; ///////////////
        pair<int,int> temp;
        stack<pair<int,int>> stk;
        bool isIdle = false;
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            isIdle = false;
            while(temp.second != -1 && (ans-temp.second)<n){
                // cout<<"hi";
                if(!pq.empty()){
                    stk.push(temp);
                    temp = pq.top();
                    pq.pop();
                }else{
                    isIdle=true;
                    break;
                }
            }
            ans++;
            if(!isIdle){
                temp.first--;
                temp.second=ans;
                if(temp.first!=0){
                    pq.push(temp);
                }
                // cout<<"@"<<temp.second<<"->";
            }else{
                // cout<<"idle->";
                pq.push(temp);
            }

            while(!stk.empty()){
                temp=stk.top();
                stk.pop();
                pq.push(temp);
            }

        }



        return ans;
    }
};