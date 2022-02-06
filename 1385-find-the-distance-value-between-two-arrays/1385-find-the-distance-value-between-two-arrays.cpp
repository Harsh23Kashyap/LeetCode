class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int c=0;
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        
        for(int i=0;i<arr1.size();i++)
        {
            bool happens=true;
            for(int j=0;j<arr2.size();j++)
            {
                if(abs(arr1[i]-arr2[j])<=d)
                {
                    happens=false;
                    break;
                }
            }
            if(happens)
            {
                c++;
            }
        }
        return c;
    }
};