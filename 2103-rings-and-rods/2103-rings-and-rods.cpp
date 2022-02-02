class Solution {
public:
    int countPoints(string rings) 
    {
        int c=0;
        for(int i='0';i<='9';i++)
        {
            set<char> s;
            for(int j=1;j<rings.length();j++)
            {
                if(rings[j]==i)
                    s.insert(rings[j-1]);
            }
            if(s.size()==3) c++;
        }
        return c;
    }
};