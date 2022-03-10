class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        vector<int> prefix;
        prefix.push_back(0);
        prefix.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            prefix.push_back(prefix[i]+arr[i]);
        }
        prefix.push_back(0);
        for(int i=0;i<prefix.size();i++)
        {
            cout<<prefix[i]<<endl;
        }
        int sum=0;
        for(int i=1;i<=arr.size();i+=2)
        {
            cout<<"For size "<<i<<endl;
            for(int j=0;j<=arr.size()-i;j++)
            {
                cout<<"Value"<<endl;
                cout<<j+i<<endl;
                cout<<j<<endl;
                cout<<(prefix[j+i]-prefix[j])<<endl;
                
                sum+=(prefix[j+i]-prefix[j]);
            }
        }
        return sum;
        
    }
};