class Solution {
public:
    bool pass(vector<int> &a,int t, int m)
    {
        int sum=0;
        for(int i=0;i<m;i++)
            sum+=a[i];
        if(sum>=t) 
        {
            cout<<"Sum- "<<sum<< " from 0 " <<" to "<<m-1<<endl;
                return true;
        }
        for(int j=m;j<a.size();j++)
        {
            sum=sum+a[j]-a[j-m];
            if(sum>=t) 
            {
                cout<<"Sum- "<<sum<< " from "<<j-m+1 <<" to "<<j<<endl;
                return true;
            }
        }
        return false;
    }
    int minSubArrayLen(int t, vector<int>& a) 
    {
        if(accumulate(a.begin(), a.end(), 0)<t) return 0;
        if(accumulate(a.begin(), a.end(), 0)==t) return a.size();
        int l=1;
        int h=a.size();
        int mid;
        int res;
        while(l<=h)
        {
            mid=(l+h)/2;
            cout<<mid<<endl;
            bool check=pass(a,t,mid);
            if(check) 
            {
                res=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};