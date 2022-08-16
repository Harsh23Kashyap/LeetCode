class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        unordered_set<int> s(arr.begin(),arr.end());
        int maxi=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int x=arr[i],y=arr[j];
                int curr=2;
                while(s.find(x+y)!=s.end())
                {
                    curr++;
                    int temp=x+y;
                    x=y,y=temp;
                }
                maxi=max(curr,maxi);
            }
        }
        return maxi>=3?maxi:0;
        
    }
};