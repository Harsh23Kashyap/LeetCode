class Solution {
public:
    long double  slope(vector<int> p1,vector<int> p2)
    {
        if(p1[0]==p2[0])
            return INT_MAX;
        return (long double)(p2[1]-p1[1])/(long double)(p2[0]-p1[0]);
    }
    int minimumLines(vector<vector<int>>& sp) 
    {
        sort(sp.begin(),sp.end());
        int n=sp.size();
        cout<<n<<endl;
        if(n<=2)
            return n-1;
        long double  ps=INT_MIN;
        //cout<<"0 and 1- "<<ps<<endl;
        int c=0;
        for(int i=0;i<n-1;i++)
        {
            // cout<<"Point 1- "<<sp[i][0]<<","<<sp[i][1]<<endl;
            // cout<<"Point 2- "<<sp[i+1][0]<<","<<sp[i+1][1]<<endl;
            long double ns=slope(sp[i],sp[i+1]);
             // cout<<i<<" and "<<i+1<<" -"<<ns<<endl;
            if(ns!=ps)
            {
                ps=ns;
                c++;
            }
        }
        
        return c;
    }
};