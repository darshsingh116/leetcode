struct Node {
    Node *listings[26];
    bool wordEnd;

    Node(){
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            listings[i] = nullptr;
        }
    }
};
class Trie {
public:
    Node *root = new Node();
    Trie() {}
    
    void insert(string word) {
        Node *ptr = root;
        for(int i=0;i<word.size();i++){
            if(ptr->listings[word[i]-'a']!=nullptr){
                ptr=ptr->listings[word[i]-'a'];
            }else{
                Node *temp = new Node();
                ptr->listings[word[i]-'a'] = temp;
                ptr=temp;
            }
        }
        ptr->wordEnd = true;
    }
    
    bool search(string word) {
        Node *ptr = root;
        for(int i=0;i<word.size();i++){
            if(ptr->listings[word[i]-'a']!=nullptr){
                ptr=ptr->listings[word[i]-'a'];
            }else{
                return false;
            }
        }
        return (ptr->wordEnd);
    }
    
    bool startsWith(string prefix) {
        Node *ptr = root;
        for(int i=0;i<prefix.size();i++){
            if(ptr->listings[prefix[i]-'a']!=nullptr){
                ptr=ptr->listings[prefix[i]-'a'];
            }else{
                return false;
            }
        }
        queue<Node*> q;
        q.push(ptr);
        while(!q.empty()){
            ptr=q.front();
            q.pop();
            if(ptr->wordEnd){
                return true;
            }
            for(int i=0;i<26;i++){
                if(ptr->listings[i]!=nullptr){
                    q.push(ptr->listings[i]);
                }
            }
        }

        return false;
        
        
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */