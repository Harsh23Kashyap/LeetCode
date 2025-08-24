class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0;
        int c=0;
        int maxi=0;
        while(r<nums.size()){
            if(nums[r]==0){
                c++;
               
            }
             while(c>1 and l<r){
                // cout<<"Reducing "<<c<<" to "<<nums[l]<<" l"<<endl;
                // cout<<l<<" ->"<<c<<endl;
                if(nums[l]==0)
                    c--;
                l++;
            }
            // cout<<l<<" "<<r<<" "<<c<<endl;
            maxi=max(maxi,r-l);
            r++;
        }
        return maxi;
    }
};