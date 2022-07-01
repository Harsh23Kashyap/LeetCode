class Solution {
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int count=0;
        for(int i=0;i<boxTypes.size();i++)
        {
            int no=boxTypes[i][0];
            int item=boxTypes[i][1];
            if(no<truckSize)
            {
                count+=no*item;
                cout<<count;
                truckSize=truckSize-(no);
                cout<<truckSize<<endl;
            }
            else
            {
                count+=truckSize*item;
                return count;
            }
        }
        return count;
        
    }
};