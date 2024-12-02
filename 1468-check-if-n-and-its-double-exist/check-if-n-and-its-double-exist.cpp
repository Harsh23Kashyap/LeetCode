class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        //sort(arr.begin(),arr.end())
        unordered_map<int,int> u;
        for(int i:arr)
            u[i]++;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0 )
            {
                if(u[0]>1)return true;
                else continue;
            }
            
            else if((arr[i]%2==0 and u.find(arr[i]/2)!=u.end() )|| u.find(arr[i]*2)!=u.end())
            {
                cout<<arr[i];
                return true;
            }
        }
        return false;
    }
};