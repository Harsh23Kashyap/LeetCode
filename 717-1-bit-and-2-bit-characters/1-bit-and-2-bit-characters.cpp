class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        bool last=true;
        for(int i=0;i<bits.size();i++)
        {
            if(bits[i]==1)
            {
                last=false;
                i++;
            }
            else
            {
                last=true;
            }
        }
        return last;
    }
};