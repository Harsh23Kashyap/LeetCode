class Solution {
public:
    bool valid(string &s) 
    {
        int hyphen = 0, N = s.size();
        for (int i = 0; i < N; ++i) 
        {
            if (isdigit(s[i])) 
                return false; // no digit
            if (isalpha(s[i])) 
                continue; // skip letters
            if (s[i] == '-') 
            {
                if (++hyphen > 1)
                    return false; // at most one hyphen allowed
                if (i - 1 < 0 || !isalpha(s[i - 1]) || i + 1 >= N || !isalpha(s[i + 1])) 
                    return false; // hyphen must be surrounded by letters
            } 
            else if (i != N - 1) 
                return false; // punctuation, if any, must be the last character of token
        }
        return true;
    }
    int countValidWords(string sentence)
    {
        //int count=0;
        stringstream s(sentence);
        string temp;
        int c=0;
        while(s>>temp)
        {
            if(valid(temp))
                c++;
        }
        return c;
    }
};