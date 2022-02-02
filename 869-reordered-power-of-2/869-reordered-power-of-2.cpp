class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        string s=to_string(n);
        sort(s.begin(),s.end());
        for(int i=0;i<30;i++)
        {
            //cout<<i<<endl;
            long p=pow(2,i);
            string curr=to_string(p);
            if(curr.length()>s.length())
                break;
            sort(curr.begin(),curr.end());
            if( curr==s)
                return true;
        }
        return false;
        
        
    }
};