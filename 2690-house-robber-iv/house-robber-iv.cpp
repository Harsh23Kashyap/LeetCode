class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=1;

        int low=mini, high=maxi;
        while(low<high){
            int mid=low+(high-low)/2;
            int c=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<=mid){
                    c++;
                    i++;
                }
            }
            cout<<mid<<" "<<c<<endl;
            if(c>=k)
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};