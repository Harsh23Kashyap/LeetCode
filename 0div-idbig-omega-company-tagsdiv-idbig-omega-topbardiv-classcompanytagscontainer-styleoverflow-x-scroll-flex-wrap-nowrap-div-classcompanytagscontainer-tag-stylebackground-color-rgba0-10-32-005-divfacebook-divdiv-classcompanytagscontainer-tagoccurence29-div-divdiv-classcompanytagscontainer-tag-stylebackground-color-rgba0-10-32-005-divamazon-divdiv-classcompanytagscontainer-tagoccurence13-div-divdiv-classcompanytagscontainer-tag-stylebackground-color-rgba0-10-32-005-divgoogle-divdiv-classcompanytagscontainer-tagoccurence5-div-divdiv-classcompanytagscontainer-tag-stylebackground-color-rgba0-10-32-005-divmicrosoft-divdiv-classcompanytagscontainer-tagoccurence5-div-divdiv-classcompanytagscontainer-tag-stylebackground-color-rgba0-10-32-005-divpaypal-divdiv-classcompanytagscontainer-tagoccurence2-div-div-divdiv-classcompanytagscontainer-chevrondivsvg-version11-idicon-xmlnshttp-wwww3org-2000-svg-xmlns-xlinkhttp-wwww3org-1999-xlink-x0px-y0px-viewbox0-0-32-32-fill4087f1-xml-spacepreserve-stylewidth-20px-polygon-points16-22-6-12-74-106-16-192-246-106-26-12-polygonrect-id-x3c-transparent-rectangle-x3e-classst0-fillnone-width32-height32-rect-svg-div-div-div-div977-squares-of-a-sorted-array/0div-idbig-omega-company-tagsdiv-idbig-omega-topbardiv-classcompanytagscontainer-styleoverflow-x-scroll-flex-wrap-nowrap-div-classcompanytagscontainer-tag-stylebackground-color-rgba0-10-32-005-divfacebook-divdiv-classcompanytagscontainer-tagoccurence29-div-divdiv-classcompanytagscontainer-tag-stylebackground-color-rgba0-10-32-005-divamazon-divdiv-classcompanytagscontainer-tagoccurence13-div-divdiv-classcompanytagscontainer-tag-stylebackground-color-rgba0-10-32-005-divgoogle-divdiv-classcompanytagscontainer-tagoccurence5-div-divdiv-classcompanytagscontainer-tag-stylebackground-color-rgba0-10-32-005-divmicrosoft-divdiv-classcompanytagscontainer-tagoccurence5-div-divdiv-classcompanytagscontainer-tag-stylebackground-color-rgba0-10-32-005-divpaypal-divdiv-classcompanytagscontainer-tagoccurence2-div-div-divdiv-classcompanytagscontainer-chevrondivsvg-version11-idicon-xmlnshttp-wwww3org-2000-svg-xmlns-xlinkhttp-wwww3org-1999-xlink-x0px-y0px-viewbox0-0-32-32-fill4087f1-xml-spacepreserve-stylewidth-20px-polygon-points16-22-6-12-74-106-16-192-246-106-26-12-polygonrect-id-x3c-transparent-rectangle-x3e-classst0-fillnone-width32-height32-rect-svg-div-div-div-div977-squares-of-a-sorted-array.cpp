class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        //int j=nums.size()-1;
        int j=0;
        for (int i=nums.size()-1;i>=0;i--)
        {
            if(nums[j]*nums[j]>nums[i]*nums[i])
            {
                nums.insert(nums.begin()+i+1,nums[j]*nums[j]);
                nums.erase(nums.begin()+j);
                //j++;
            }
            else
                nums[i]*=nums[i];
            // for(int i=0; i<nums.size(); i++)
            // {
            //     cout << nums[i] << " ";
            // }
            // cout << "\n" << endl;
        }
        return nums;
    }
};