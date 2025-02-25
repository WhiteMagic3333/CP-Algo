int solution(string alienCode) {
    int count = 0;
    int n = alienCode.length();
    
    // Generate all possible substrings
    for (int i = 0; i < n; i++) {
        if (alienCode[i] == '0'){
            count++;
            continue; // Ignore leading zeros
        }
        
        int num = 0;
        for (int j = i; j < n; j++) {
            num = num + (alienCode[j] - '0'); // Convert substring to integer
            
            if (num % 3 == 0) {
                count++;
            }
        }
    }
    
    return count;
}