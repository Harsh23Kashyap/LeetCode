class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        map<int,int> m;
        for(int i:nums)
            m[i]++;
        int best=0;
        int prevnum=INT_MIN,prevval;
        for(auto i:m)
        {
            //cout<<i.first<<" "<<i.second<<endl;
            if(prevnum!=INT_MIN)
            {
                //cout<<"runs";
                if(i.first-prevnum==1)
                    best=max(best,prevval+i.second);
            }
            prevnum=i.first;
            prevval=i.second;
        }
        return best;
    }
};