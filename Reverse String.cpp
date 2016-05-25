class Solution {
public:
    string reverseString(string s) {
        char *str = new char[s.size() + 1];
        strcpy(str, s.c_str());
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            swap(str[i], str[j]);
        }
        return string(str);
    }
};