string countAndSay(int n) {
    string str("1");
    for (int i = 1; i < n; i++) {
        char ch = str[0];
        int count = 0;
        string tmp;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == ch) {
                count++;
            } else {
                tmp += (to_string(count) + ch);
                ch = str[j];
                count = 1;
            }
        }
        tmp += (to_string(count) + ch);
        str = tmp;
    }
    return str;
}
