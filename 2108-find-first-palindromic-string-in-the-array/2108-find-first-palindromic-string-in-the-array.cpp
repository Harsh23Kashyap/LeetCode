class Solution {
public:
    string firstPalindrome(vector<string>& words) 
    {
        for (int i=0;i<words.size();i++)
        {
            string rev=string(words[i].rbegin(),words[i].rend());
            if(words[i]==rev)
                return words[i];
        }
        return "";
    }
};