class Solution 
{
public:
    int possible(vector<int>& nums, int mid)
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=mid)
                c++;
        }
        if(c==mid)
            return 1;
        if(c>mid) return 2;
        return 0;
    }
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        int low=1;
        int high=min(nums[0],n);
        int best=-1;
        int mid=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            cout<<"X -  "<<mid<<endl;
            int k=possible(nums,mid);
            if(k==1)
            {
                cout<<"runs"<<endl;
                best=mid;
                low=mid+1;
            }
            else if(k==2) low=mid+1;
            else high=mid-1;
        }
        return best;
    }
};