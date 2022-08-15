class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        map<long long, int> u;
        for(int i=0;i<nums1.size();i++)
            u[abs(nums1[i]-nums2[i])]++;
        
        int k=k1+k2;
        for (auto it = u.rbegin(); it != u.rend(); it++) 
        {
            if(k==0)
                break;
            int val=it->first,count=it->second;
            if(val==0)
                break;
            if(u.find(val-1)==u.end())
                u[val-1]=0;
            
            if(count<=k)
            {
                u[val-1]+=u[val];
                u[val]=0;
                k-=count;
            }
            else
            {
                u[val-1]+=k;
                u[val]-=k;
                k=0;
            }
        }
        
        long long res=0;
        for(auto it:u)
        {
            res+=(it.first)*(it.first)*it.second;
        }
        return res;
        
    }
};