class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        vector<string> morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ans;
        for(string s:words)
        {
            string temp="";
            for(char ch:s)
            {
                temp+=morse[ch-'a'];
            }
            ans.insert(temp);
        }
        return ans.size();
        
    }
};