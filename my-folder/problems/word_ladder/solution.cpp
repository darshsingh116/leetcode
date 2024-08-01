class Solution {
public:
    bool check(string a,string b){
        int len = a.size();
        int n=0;
        if(len%2==1){
            if(a[len/2]!=b[len/2]){
                n++;     
            }
        }
        for(int i=0;i<=(len/2)-1;i++){
            if(a[i]!=b[i]){
                n++;     
            }
            if(a[len-i-1]!=b[len-i-1]){
                n++;  
            }
            if(n>1){return false;}
            
        }
        if(n==1){return true;}
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string,vector<string>> graph;
        for(int i=0;i<wordList.size();i++){
            graph[wordList[i]] = {};
        }
        for(int i=0;i<wordList.size()-1;i++){
            for(int j=i+1;j<wordList.size();j++){
                if(check(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        if(graph.find(endWord)==graph.end()){return 0;}

        queue<pair<string,int>> q;

        q.push({beginWord,1});

        pair<string,int> curr;
        string s;
        int ans=1;
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()){
            curr=q.front();
            s=curr.first;
            ans=curr.second;
            q.pop();
            ans++;
            for(auto x:graph[s]){
                if(x==endWord){
                    return ans;
                }
                if(visited.find(x)==visited.end()){
                    visited.insert(x);
                    q.push({x,ans});
                    
                }    
            }
            
        }
        return 0;
    }
};