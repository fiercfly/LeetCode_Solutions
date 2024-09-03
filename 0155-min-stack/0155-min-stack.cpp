class MinStack {
public:
    stack<int> st;
    stack<int> st2;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(st2.empty()){
            st2.push(val);
        }
        else{
            if(val < st2.top()){
                st2.push(val);
            }
            else{
                int x= st2.top();
                st2.pop();
                st2.push(val);
                st2.push(x);
            }
        }
    }
    
    void pop() {
        int x= st.top();
        st.pop();
        stack<int> temp;
        while(st2.top()!= x){
            temp.push(st2.top());
            st2.pop();
        }
        st2.pop();
        while(!temp.empty()){
            st2.push(temp.top());
            temp.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */