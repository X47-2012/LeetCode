bool existHelper(vector<vector<char>>& board, string word, int len, int i, int j) {
    if (len == word.size()) {
        return true;
    }
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
        return false;
    }
    if (word[len] != board[i][j] || board[i][j] == '*') {
        return false;
    }
    
    char ch = board[i][j];
    board[i][j] = '*';
    bool flag = existHelper(board, word, len + 1, i - 1, j) ||
                existHelper(board, word, len + 1, i + 1, j) ||
                existHelper(board, word, len + 1, i, j - 1) ||
                existHelper(board, word, len + 1, i, j + 1);
    board[i][j] = ch;
    return flag;
}


bool exist(vector<vector<char>>& board, string word) {
    if (word.size() == 0) {
        return true;
    }
    if (board.size() == 0 || board[0].size() == 0) {
        return false;
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (existHelper(board, word, 0, i, j)) {
                return true;
            }
        }
    }
    return false;
}