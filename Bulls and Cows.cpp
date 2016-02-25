string getHint(string secret, string guess) {
    int A = 0, B = 0;
    int recordS[10];
    int recordG[10];
    memset(recordS, 0, 10 * sizeof(int));
    memset(recordG, 0, 10 * sizeof(int));
    
    for (int i = 0; i < guess.size(); i++) {
        if (guess[i] == secret[i]) {
            A++;
        } else {
            recordS[secret[i] - '0'] += 1;
            recordG[guess[i] - '0'] += 1;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        B += min(recordG[i], recordS[i]);
    }
    
    string ans = std::to_string(A) + 'A' + std::to_string(B) + 'B';
    return ans;
}