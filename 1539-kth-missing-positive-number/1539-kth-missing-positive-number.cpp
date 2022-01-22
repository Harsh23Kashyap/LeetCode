class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {

        for(int i=1;i<=1000+arr.size();i++)
        {
            auto it=find(arr.begin(),arr.end(),i);
            if(it==arr.end())
                k--;
            if(k==0) return i;
        }
        return -1;
    }
};