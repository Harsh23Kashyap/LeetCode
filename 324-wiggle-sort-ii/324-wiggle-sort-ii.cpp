class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        // for(int i=1;i<nums.size();i+=2)
        // {
        //     if(nums[i]<nums[i-1])
        //         swap(nums[i],nums[i-1]);
        //     if(i!=nums.size()-1 and nums[i]<nums[i+1])
        //         swap(nums[i],nums[i+1]);
        // }
//         sort(nums.begin(),nums.end());
        
//         int n=nums.size();
//         int k=n-1;
//         vector<int>ans(n,0);
//         for(int i=1;i<n;i+=2)
//             ans[i]=nums[k--];
//         k=0;
//         for(int i=0;i<n;i+=2)
//             ans[i]=nums[k++];
        
//         for(int i=0;i<n;i++)
//             nums[i]=ans[i];
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; i--)
        {
            if(i%2==0)
                nums[i]=sorted[j++];
            else
                nums[i]=sorted[k++];
        }
    }
};