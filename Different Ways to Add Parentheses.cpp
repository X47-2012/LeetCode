class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> output;
        if (input.size() == 0) {
            return output;
        }
        if (input.find('-') == string::npos && input.find('+') == string::npos && input.find('*') == string::npos) {
            output.push_back(atoi(input.c_str()));
            return output;
        }
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+') {
                vector<int> left_vec = diffWaysToCompute(input.substr(0, i));
                vector<int> right_vec = diffWaysToCompute(input.substr(i + 1, string::npos));
                for (int left : left_vec) {
                    for (int right : right_vec) {
                        output.push_back(left + right);
                    }
                }
            } else if (input[i] == '*') {
                vector<int> left_vec = diffWaysToCompute(input.substr(0, i));
                vector<int> right_vec = diffWaysToCompute(input.substr(i + 1, string::npos));
                for (int left : left_vec) {
                    for (int right : right_vec) {
                        output.push_back(left * right);
                    }
                }
            } else if (input[i] == '-') {
                vector<int> left_vec = diffWaysToCompute(input.substr(0, i));
                vector<int> right_vec = diffWaysToCompute(input.substr(i + 1, string::npos));
                for (int left : left_vec) {
                    for (int right : right_vec) {
                        output.push_back(left - right);
                    }
                }
            }
        }
        sort(output.begin(), output.end());
        return output;
    }
};