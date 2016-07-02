class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto token : tokens) {
            if (!is_operator(token)) {
                stk.push(stoi(token));
            } else {
                int y = stk.top();
                stk.pop();
                int x = stk.top();
                stk.pop();
                
                if (token == "+") {
                    stk.push(x + y);
                } else if (token == "*") {
                    stk.push(x * y);
                } else if (token == "-") {
                    stk.push(x - y);
                } else if (token == "/") {
                    stk.push(x / y);
                }
            }
        }
        return stk.top();
    }
private:
    bool is_operator(const string &op) {
        return (op.size() == 1) && (string("+-*/").find(op) != string::npos);
    }
};