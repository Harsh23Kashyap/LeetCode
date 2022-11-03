class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string, int> count;
        for (const string& word : words) 
            count[word]++;
        

        int answer = 0;
        bool central = false;

        for (auto& [word, countOfTheWord] : count) 
        {
            // if the word is a palindrome
            if (word[0] == word[1]) 
            {
                if (countOfTheWord % 2 == 0) 
                     answer += countOfTheWord;
                else 
                {
                    answer += countOfTheWord - 1;
                    central = true;
                }
               
            } 
            else if (word[0] < word[1] and count.find({word[1], word[0]})!=count.end()) {
                answer += 2 * min(countOfTheWord, count[{word[1], word[0]}]);
            }
        }

        if (central) {
            answer++;
        }
        return 2 * answer;
    }
};