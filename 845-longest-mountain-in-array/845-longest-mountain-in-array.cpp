class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int res=0;
        for(int i=1;i<arr.size();i++)
        {
            int j=i;
            int c1=0;
            while(j<arr.size() and arr[j]>arr[j-1])
            {
                j++;
                c1++;
            }
            int c2=0;
            while(i!=j and j<arr.size() and arr[j-1]>arr[j])
            {
                j++;
                c2++;
            }
            if(c1==0 or c2==0)
                continue;
            // if(j==arr.size())
            //     c2++;
            
            res=max(res,c1+c2+1);
             cout<<i<<" - "<<c1<<" "<<c2<<endl;
        }
        return res==1?0:res;
        
    }
};