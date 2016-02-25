class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0, index2 = 0;
        int n1 = version1.size();
        int n2 = version2.size();
        
        while (index1 < n1 && index2 < n2) {
            string numStr1, numStr2;
            while (index1 < n1 && version1[index1] != '.') {
                numStr1 += version1[index1];
                index1++;
            }
            while (index2 < n2 && version2[index2] != '.') {
                numStr2 += version2[index2];
                index2++;
            }
            int num1 = atoi(numStr1.c_str());
            int num2 = atoi(numStr2.c_str());
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
            index1++;
            index2++;
        }
        
        if (index1 >= n1 && index2 >= n2) {
            return 0;
        } else if (index1 >= n1) {
            while (index2 < n2) {
                string numStr2;
                while (index2 < n2 && version2[index2] != '.') {
                    numStr2 += version2[index2];
                    index2++;
                }
                int num2 = atoi(numStr2.c_str());
                if (num2 != 0) {
                    return -1;
                }
                index2++;
            }
            return 0;
        } else {
            while (index1 < n1) {
                string numStr1;
                while (index1 < n1 && version1[index1] != '.') {
                    numStr1 += version1[index1];
                    index1++;
                }
                int num1 = atoi(numStr1.c_str());
                if (num1 != 0) {
                    return 1;
                }
                index1++;
            }
            return 0;
        }
    }
};