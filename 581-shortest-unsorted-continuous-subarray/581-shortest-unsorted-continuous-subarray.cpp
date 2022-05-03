class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        vector<int> copy=nums;
        sort(copy.begin(),copy.end());
        int s=0,e=0;
        for(int i=0;i<nums.size();i++)
        {
            //cout<<i<<endl;
            if(nums[i]!=copy[i])
            {
                s=i;
                break;
                
            }
        }
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            //cout<<i<<endl;
            if(nums[i]!=copy[i])
            {
                e=i+1;
                break;
                
            }
        }
        cout<<e<<s<<endl;
        return e-s;
        
    }
};