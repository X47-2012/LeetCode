bool isPalindrome(const string s) {
    if (s.size() <= 1) {
        return true;
    }
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++; j--;
    }
    return true;
}

void partitionHelper(string s, vector<string> &path, vector<vector<string> > &ans) {
    if (s.size() == 0) {
        ans.push_back(path);
    }
    for (int i = 1; i <= s.size(); i++) {
        string tmp = s.substr(0, i);
        if (isPalindrome(tmp)) {
            path.push_back(tmp);
            partitionHelper(s.substr(i, s.size() - i), path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<string> path;
    vector<vector<string> > ans;
    if (s.size() == 0) {
        return ans;
    }
    partitionHelper(s, path, ans);
    return ans;
}