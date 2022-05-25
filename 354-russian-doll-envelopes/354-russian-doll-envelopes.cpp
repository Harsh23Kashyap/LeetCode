class Solution {
public:
    int bSearch(vector<int>& vec, int maxVal, vector<vector<int>>& envelopes, int i)
    {
        int l = 0;
        int r = maxVal;
        
        int temp = maxVal;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(vec[mid] < envelopes[i][1])
                l = mid + 1;
            
            else {
                temp = mid;
                r = mid - 1;
            }
        }
        
        return temp;
    }
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>v(envelopes.size(),0);
        int maxi=0;
       for(int i=0;i<envelopes.size();i++)
       {
           int search=bSearch(v,maxi,envelopes,i);
            v[search] = envelopes[i][1];
            if(search == maxi)
                maxi++;
       }
        return maxi;

        
    }
};