class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels_set( {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'} );
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (vowels_set.count(s[i]) > 0 && vowels_set.count(s[j]) > 0) {
                swap(s[i], s[j]);
            } else if (vowels_set.count(s[i]) > 0) {
                i--;
            } else if (vowels_set.count(s[j]) > 0) {
                j++;
            }
        }
        return s;
    }
};