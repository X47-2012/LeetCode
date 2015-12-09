#include <string>

bool helper(string s, int left, int right) {
	while (left < right) {
		if (s[left] != s[right]) {
			return false;
		}
		left++; right--;
	}
	return true;
}

string shortestPalindrome(string s) {
	if (s.size() == 0) {
		return s;
	}

	int start = s.find_not_first_of(s[0]);
	int end;

	if (start == -1) {
		return s;
	}

    for (int i = s.size() - 1; i >= 0; i--) {
    	if (s[i] == s[0]) {
    		end = s.find_not_last_of(s[0], i);
    		if (i - end >= start) {
    			if (helper(s, start, end) == true) {
    				string tmp = s.substr(end + start + 1);
    				reverse(tmp.begin(), tmp.end());
    				return tmp + s;
    			} else {
    				i = end;
    			}
    		} else {
    			i = end;
    		}
    	}
    }

    string tmp = s.substr(1);
    reverse(tmp.begin(), tmp.end());
    return tmp + s;
}