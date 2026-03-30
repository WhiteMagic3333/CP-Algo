#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isVowel(char c) {
    char lowerC = tolower(c);
    return lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u';
}

vector<string> solution(vector<string> text) {
    for (string& word : text) {
        if (word.length() >= 3) {
            if (isVowel(word.front()) && isVowel(word.back())) {
                reverse(word.begin() + 1, word.end() - 1);
            }
        }
    }
    
    return text;
}