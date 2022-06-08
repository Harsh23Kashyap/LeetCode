class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        unordered_map<char,int> st;
        for(char ch:stones)
            st[ch]=0;
        
        for(char ch:stones)
            st[ch]++;
        
        int count=0;
        
        for(int i=0;i<jewels.size();i++)
        {
            if(st.find(jewels[i])!=st.end())
                count+=st[jewels[i]];
        }
        return count;
        
    }
};