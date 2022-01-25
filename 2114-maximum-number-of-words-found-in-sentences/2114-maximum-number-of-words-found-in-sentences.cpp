class Solution {
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int count=0;
        for(int i=0;i<sentences.size();i++)
        {
            stringstream s(sentences[i]);
            string temp;
            int c=0;
            while(s>>temp)
                c++;
            count=max(count,c);
        }
        return count;
    }
};