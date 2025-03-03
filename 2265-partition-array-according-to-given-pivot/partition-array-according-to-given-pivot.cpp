class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int sz=nums.size();
        int c=0;
        int same=0;
        for(auto it:nums)
        {
            if(it<pivot)
            c++;
            if(it==pivot)
            same++;
        }
        int i=0,j=c+same,k=c;
        vector<int> ans(sz,0);
        for(auto it:nums){
            // cout<<it<<" "<<i<<" "<<j<<endl;
            if(it<pivot){
                ans[i++]=it;
            }
            else if(it>pivot){
                ans[j++]=it;
            }
            else{
                ans[k++]=it;
            }
        }
        return ans;
    }
};