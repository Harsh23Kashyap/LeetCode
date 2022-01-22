class Solution {
public:
    vector<int> constructArray(int n, int k) 
    {
        vector<int> v;
        int i=1,j=n;
        while(k>1)
        {
            k-=2;
            v.push_back(i++);
            v.push_back(j--);
        }
        if(k==0)
        {
            for(int f=j;f>=i;f--)
                v.push_back(f);
        }
        else
        {
            for(int f=i;f<=j;f++)
                v.push_back(f);
        }
        
        return v;
        
    }
};