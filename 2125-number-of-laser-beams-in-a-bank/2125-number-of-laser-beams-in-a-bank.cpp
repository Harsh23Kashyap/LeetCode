class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        vector<int> count;
        for(int i=0;i<bank.size();i++)
        {
            int c=0;
            for(char ch:bank[i])
            {
                if(ch=='1')
                    c++;
            }
            count.push_back(c);
        }
        
        
        int tot=0,prev=0;
        for(int i=0;i<count.size();i++)
        {
            if(count[i]!=0)
            {
                tot+=prev*count[i];
                prev=count[i];
            }
        }
        return tot;
        
    }
};