class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        int count = 1;
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string word = q.front();
                q.pop();
                if(word == endWord) return count;
                st.erase(word);
                for(int j = 0; j < word.size(); j++){
                    char c = word[j];
                    for(int k = 0; k < 26; k++){
                        word[j] = 'a'+k;
                        if(st.find(word) != st.end()){
                            q.push(word);
                        }
                    }
                    word[j] = c;
                }
            }
            count++;
        }
        return 0;
    }
};