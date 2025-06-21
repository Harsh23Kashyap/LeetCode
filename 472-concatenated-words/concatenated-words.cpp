class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, bool> memo;

    bool canForm(string word) {
        if (memo.find(word)!=memo.end()) 
            return memo[word];

        for (int i = 1; i < word.size(); ++i) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);
            
            if (dict.find(prefix)!=dict.end()) {
                if (dict.find(suffix)!=dict.end() or canForm(suffix)) {
                    return memo[word] = true;
                }
            }
        }
        return memo[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (auto word : words) {
            dict.insert(word);
        }

        vector<string> result;

        for (auto word : words) {
            dict.erase(word);  
            if (canForm(word)) 
                result.push_back(word);
            dict.insert(word);  
        }

        return result;
    }

};