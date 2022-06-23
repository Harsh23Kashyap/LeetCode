class Solution {
public:
    int minTimeToType(string word) 
    {
        int count=0;
        char curr='a';
        
        for(char ch:word)
        {
            int op1=abs(ch-curr);
            int x=min(op1,26-op1);
            curr=ch;
            //cout<<x<<endl;
            count+=x+1;
        }
        return count;
        
    }
};