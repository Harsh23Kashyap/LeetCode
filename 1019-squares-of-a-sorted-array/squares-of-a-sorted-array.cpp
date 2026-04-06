class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=0;
        while(i<nums.size() and nums[i]<0)
        i++,j++;
        j--;
        vector<int> ans;
        while(i<nums.size() and nums[i]==0){
            ans.push_back(nums[i]);
            i++;
        }

        cout<<i<<" "<<j<<endl;

        while(j>=0 or i<nums.size()){
            cout<<i<<" "<<j<<endl;
            if(j>=0 and i<nums.size()){
                if(abs(nums[j])<=nums[i]){
                    ans.push_back(nums[j]*nums[j]);
                    j--;
                }
                else if(abs(nums[j])>nums[i]){
                    ans.push_back(nums[i]*nums[i]);
                    i++;
                }

            }
            else if(i<nums.size())
            {
                 ans.push_back(nums[i]*nums[i]);
                    i++;
            }
            else if (j>=0){
                ans.push_back(nums[j]*nums[j]);
                    j--;
            }
        } 
        return ans;
    }
};