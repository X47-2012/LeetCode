public class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] strs = preorder.split(",");
        Stack<String> s = new Stack<>();
        
        for (int i = strs.length - 1; i >= 0; i--) {
            if (strs[i].equals("#")) {
                s.push(strs[i]);
            } else if (s.size() >= 2) {
                s.pop();
                s.pop();
                s.push(strs[i]);
            } else {
                return false;
            }
        }
        
        if (s.size() == 1 && s.peek().equals(strs[0])) {
            return true;
        } else {
            return false;
        }
    }
}