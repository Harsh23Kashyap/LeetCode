class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) 
    {
        vector<int> copy=arr;
        sort(copy.begin(),copy.end());
        vector<int> ans;
        
        for(int j=copy.size()-1;j>=0;j--)
        {
            int index=(find(arr.begin(),arr.end(),copy[j])-arr.begin());
            if(index==j)
                continue;
            
            //flip;
            ans.push_back(index+1);
            reverse(arr.begin(),arr.begin()+index+1);
            ans.push_back(j+1);
            reverse(arr.begin(),arr.begin()+j+1);
        }
        if(ans.size()>10*arr.size())
        {
            vector<int> d;
            return d;
        }
        return ans;
    }
};