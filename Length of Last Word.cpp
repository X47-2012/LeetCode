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
