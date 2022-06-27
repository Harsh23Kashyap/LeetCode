class Solution {
public:
    int minPartitions(string n) 
    {
        int c=0;
        char m='0';
        for(char ch:n)
        {
            if(ch>=m)
                m=ch;
        }
        return m-'0';
        
    }
};