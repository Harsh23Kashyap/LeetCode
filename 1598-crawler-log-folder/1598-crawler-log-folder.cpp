class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        stack<string> s;
        for(int i=0;i<logs.size();i++)
        {
            string a=logs[i];
            if(a=="./")
                continue;
            else if(a=="../")
            {
                if(!s.empty())
                s.pop();
            }
            else
                s.push(a);
            
        }
        return s.size();
        
    }
};