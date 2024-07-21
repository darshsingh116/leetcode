class MyQueue {
public:

    stack<int> s1,s2;
    int temp,size,ans;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        size = s1.size();
        for(int i=1;i<size;i++){
            temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        ans = s1.top();
        s1.pop();
        for(int i=1;i<size;i++){
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        
        return ans;
    }
    
    int peek() {
        size = s1.size();
        for(int i=1;i<size;i++){
            temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        ans = s1.top();
        s1.pop();
        s1.push(ans);
        for(int i=1;i<size;i++){
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        
        return ans;
        
    }
    
    bool empty() {
        return (0==s1.size());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */