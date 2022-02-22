class Solution {
public:
    int titleToNumber(string ct) 
    {
        long long size=0;
        for(int i=0;i<ct.length();i++)
        {
            char ch=ct[i];
            size=size*26+ch-'A'+1;
        }
        return size;
    }
};