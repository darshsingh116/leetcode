class MyStack {
public:
    queue<int> q1;
    int temp;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        for(int i=1;i<q1.size();i++){
            temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
        temp=q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return (q1.size()==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */