class MyQueue {
public:
    stack<int>s;
    stack<int>temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    








    int pop() {
        int val;
        if(!s.empty()){
            while(s.size()!=1){
                temp.push(s.top());
                s.pop();
            }
            val = s.top();
            s.pop();
        }
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        return val;
    }
    
    int peek() {
        // int val;
        int val;
        if(!s.empty()){
            while(!s.empty()){
                val=s.top();
                temp.push(s.top());
                s.pop();
            }
        }
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        return val;
        
    }
    
    bool empty() {
        return s.empty();
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
