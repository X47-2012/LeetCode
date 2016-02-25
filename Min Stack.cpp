class MinStack {
public:
    vector<int> stack;
    int min_val;
    
    void push(int x) {
        if (stack.empty() || x < min_val) {
            min_val = x;
        }
        stack.push_back(x);
    }

    void pop() {
        if (min_val == stack.back()) {
            min_val = INT_MAX;
            for (int i = 0; i < stack.size() - 1; i++) {
                if (stack[i] < min_val) {
                    min_val = stack[i];
                }
            }
        }
        stack.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min_val;    
    }
};