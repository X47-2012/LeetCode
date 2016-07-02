int lengthOfLastWord(string s) {
    int i = s.size();
    while (--i >= 0) {
        if (s[i] != ' ')
            break;
    }

    int len = 0;
    for (; i >= 0; i--) {
        if (s[i] == ' ')
            break;
        len++;
    }
    return len;
}

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
        auto last = find_if_not(first, s.rend(), ::isalpha);
        return distance(first, last);
    }
};