class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        bool res=false;
        int i=0;
        while(i+1<arr.size() and arr[i]<arr[i+1])
            i++;
        if(i==0 || i==arr.size()-1)
            return false;
        
        while(i+1<arr.size() and arr[i]>arr[i+1])
            i++;
        if(i==arr.size()-1) return true;
        return false;
        
    }
};