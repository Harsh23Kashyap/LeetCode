class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
     
        vector<int> v(2,-1);
        int i=0,j=numbers.size()-1;
        while(i<j)
        {
            if(numbers[i]+numbers[j]==target)
            {
                v[0]=i+1;
                v[1]=j+1;
                break;
            }
            else if(numbers[i]+numbers[j]<target)
                i++;
            else j--;
        }
        return v;
    }
};