class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        string res = "";
        int mx = word.length() - numFriends + 1;
        for(int i = 0 ; i < word.length(); ++i){
            string temp = "";
            int startPos = i;
            int endPos =  i + mx < word.length() ? i + mx : word.length();
            for(int j = startPos; j < endPos; ++j)
                temp.push_back(word[j]);
            if(temp > res)
                res = temp;
        }
        return res;
    }
};