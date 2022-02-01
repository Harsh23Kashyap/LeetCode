class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        int m=arr[arr.size()-1];
        arr[arr.size()-1]=-1;
        for(int i=arr.size()-2;i>=0;i--)
        {
            int c=arr[i];
            arr[i]=m;
            m=max(c,m);
        }
        return arr;
    }
};