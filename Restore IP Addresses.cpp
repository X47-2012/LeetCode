bool valid(string str) {
    int x = atoi(str.c_str());
    if (x == 0 && str.size() > 1) {
        return false;
    }
    if (str[0] == '0' && x != 0) {
        return false;
    }
    return (x <= 255 && x >= 0);
}

void restoreIpAddressesHelper(int leftDot, int index, string curr, vector<string> &ans) {
    if (leftDot == 0) {
        if (valid(curr.substr(index))) {
            ans.push_back(curr);
        } 
        return;
    }
    
    for (int i = 0; i < 3; i++) {
        if (index + i < curr.size() - 1 && valid(curr.substr(index, i + 1))) {
            string tmp = string(curr);
            tmp.insert(index + i + 1, ".");
            restoreIpAddressesHelper(leftDot - 1, index + i + 2, tmp, ans);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    if (s.size() == 0) {
        return ans;
    }
    string curr = string(s);
    restoreIpAddressesHelper(3, 0, curr, ans);
    return ans;
}