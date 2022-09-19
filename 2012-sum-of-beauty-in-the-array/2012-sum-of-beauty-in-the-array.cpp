class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,0);
        vector<int> right(n,INT_MIN);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
            left[i]=max(left[i-1],nums[i-1]);
        for(int i=n-2;i>=0;i--)
            right[i]=min(right[i+1],nums[i+1]);
        
        int score=0;
        for(int i=1;i<nums.size()-1;i++)
        {
            //cout<<left[i]<<" "<<right[i]<<endl;
            if(left[i]<nums[i] and right[i]>nums[i])
                score+=2;
            else if(nums[i-1]<nums[i] and nums[i]<nums[i+1])
                score++;
        }
        return score;
    }
};