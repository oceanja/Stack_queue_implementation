class MyQueue {
public:
stack<int> inp;
stack<int> out;
int peekEl=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(inp.empty()){
         peekEl=x;
        }

        inp.push(x);
    }
    
    int pop() {
        if(out.empty()){

            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }

        }
        int val=out.top();
        out.pop();
        return val;
        
    }
    
    int peek() {
        if(out.empty()){
            return peekEl;
        }

        return out.top();
    }
    
    bool empty() {
        if(inp.empty() && out.empty()){
            return true;
        }
        return false;
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
