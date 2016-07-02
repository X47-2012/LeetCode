class Solution {
public:
    bool isNumber(string s) {
        const char *s_ch = s.c_str();
        char *endptr;
        strtod(s_ch, &endptr);
        if (endptr == s_ch) { return false; }
        for (; *endptr; endptr++) {
            if (!isspace(*endptr)) return false;
        }
        return true;
    }
};