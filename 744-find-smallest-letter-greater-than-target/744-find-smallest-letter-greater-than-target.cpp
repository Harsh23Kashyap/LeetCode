class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        char next='*';
        for(int i=0;i<letters.size();i++)
        {
            if(target<letters[i])
            {
                next=letters[i];
                break;
            }
        }
        if(next=='*') return letters[0];
        return next;
        
    }
};