class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;

    CQueue() {
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        while (!stack2.empty()) {
            stack2.pop();
        }

        while (!stack1.empty()) {
            int top = stack1.top();
            stack1.pop();
            stack2.push(top);
        }

        if (stack2.empty()) {
            return -1;
        }

        int ret = stack2.top();
        stack2.pop();

        while (!stack2.empty()) {
            int top = stack2.top();
            stack2.pop();
            stack1.push(top);
        }

        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */