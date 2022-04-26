class Solution {
public:
    bool reduce(vector<int>& nums, int maxOperations, int mid)
    {
        int op=0;
        for(int i=0;i<nums.size();i++) 
        {
            if(nums[i]>mid)
            {
                op+=(int)ceil(nums[i]*1.0/mid);
            }
            else
                op++;
            //cout<<op<<endl;
            if(op>maxOperations+nums.size())
                return false;
           
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        sort(nums.begin(),nums.end(),greater<int>());
        int low=1;
        int high=nums[0];
        int pen=high;
        while(low<=high)
        {
            int mid=(low+high)/2;
            cout<<"Mid-"<<mid<<endl;
            if(reduce(nums,maxOperations,mid))
            {
                high=mid-1;
                pen=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return pen;
    }
};