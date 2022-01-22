class Solution {
public:
    void pass(vector<int>& v, int& count,int pos, int n )
    {
        if(pos>n )
            count++;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==false and (pos%i==0 or i%pos==0))
            {
                v[i]=true;
                pass(v,count, pos+1, n);
                v[i]=false;
            }
            
        }
    }
    int countArrangement(int n) 
    {
        vector<int> visited(n+1,false);
        int count=0;
        pass(visited,count,1,n);
        return count;
        
    }
};